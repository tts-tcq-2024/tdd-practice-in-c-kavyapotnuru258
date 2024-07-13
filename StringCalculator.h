#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void throw_exception_for_negatives(const int* negatives, int count) {
    if (count > 0) {
        static char message[1024] = "negatives not allowed: ";
        char buffer[32];
        for (int i = 0; i < count; ++i) {
            sprintf(buffer, "%d", negatives[i]);
            strcat(message, buffer);
            if (i < count - 1) {
                strcat(message, ", ");
            }
        }
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }
}

int add(const char* numbers) {
    if (numbers[0] == '\0') {
        return 0;
    }

    int sum = 0;
    int negatives[1024];
    int negative_count = 0;
    char* delimiters = ",\n";
    char* numbers_copy = strdup(numbers);
    
    if (numbers_copy[0] == '/' && numbers_copy[1] == '/') {
        char* newline_pos = strchr(numbers_copy, '\n');
        if (newline_pos != NULL) {
            *newline_pos = '\0';
            delimiters = numbers_copy + 2;
            numbers_copy = newline_pos + 1;
        }
    }

    char* token = strtok(numbers_copy, delimiters);
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0) {
            negatives[negative_count++] = num;
        } else if (num <= 1000) {
            sum += num;
        }
        token = strtok(NULL, delimiters);
    }

    free(numbers_copy);
    throw_exception_for_negatives(negatives, negative_count);
    return sum;
}
