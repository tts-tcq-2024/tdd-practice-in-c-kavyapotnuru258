#include "StringCalculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(const char* input) {
    if (strcmp(input, "") == 0) {
        return 0;
    }

    const char* delimiters = ",\n";  // Change to const char*
    char* numbers[100];
    int sum = 0;
    char negatives[100] = "";

    // Check for custom delimiter
    if (input[0] == '/' && input[1] == '/') {
        const char* delimiterEnd = strchr(input, '\n'); // Use const char*
        if (delimiterEnd != NULL) {
            size_t delimiterLength = delimiterEnd - input - 2;
            char* customDelimiter = (char*)malloc(delimiterLength + 1);
            strncpy(customDelimiter, input + 2, delimiterLength);
            customDelimiter[delimiterLength] = '\0';
            delimiters = customDelimiter;  // Update delimiters to custom one
            input = delimiterEnd + 1;
        }
    }

    // Tokenize the input
    char* token = strtok((char*)input, delimiters);
    while (token != NULL) {
        int number = atoi(token);
        if (number < 0) {
            strcat(negatives, token);
            strcat(negatives, ",");
        }
        if (number <= 1000) {
            sum += number;
        }
        token = strtok(NULL, delimiters);
    }

    if (strlen(negatives) > 0) {
        negatives[strlen(negatives) - 1] = '\0'; // Remove trailing comma
        fprintf(stderr, "negatives not allowed: %s\n", negatives);
        exit(EXIT_FAILURE);
    }

    return sum;
}
