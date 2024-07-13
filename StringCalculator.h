#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

int add(const char* numbers);

#endif // STRING_CALCULATOR_H
#include "StringCalculator.h"

// Function to convert an integer to a string
void int_to_str(int num, char* str) {
    sprintf(str, "%d", num); // using sprintf to convert integer to string
}

// Function to throw exception for negative numbers
void throw_exception_for_negatives(const int* negatives, int count) {
    if (count > 0) {
        char message[1024] = "negatives not allowed: ";
        char buffer[32];
        for (int i = 0; i < count; ++i) {
            int_to_str(negatives[i], buffer);
            strcat(message, buffer);
            if (i < count - 1) {
                strcat(message, ", ");
            }
        }
        perror(message);
        exit(EXIT_FAILURE);
    }
}

// Function to add numbers from the given input string
int add(const char* numbers) {
    if (!numbers || *numbers == '\0') return 0;

    const char* delimiters = ",\n";
    char* input_copy = strdup(numbers);
    char* token;
    char* original_copy = input_copy;
    int sum = 0;
    int negatives[1024];
    int negative_count = 0;

    // Handle custom delimiter
    if (strncmp(input_copy, "//", 2) == 0) {
        char* newline_pos = strchr(input_copy, '\n');
        if (newline_pos != NULL) {
            *newline_pos = '\0';
            delimiters = input_copy + 2;
            input_copy = newline_pos + 1;
        }
    }

    // Tokenize input based on delimiters
    token = strtok(input_copy, delimiters);
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0) {
            negatives[negative_count++] = num;
        } else if (num <= 1000) {
            sum += num;
        }
        token = strtok(NULL, delimiters);
    }

    free(original_copy);
    throw_exception_for_negatives(negatives, negative_count);
    return sum;
}

