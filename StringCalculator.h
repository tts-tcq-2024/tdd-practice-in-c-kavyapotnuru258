#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int add(const char* input);

#endif // STRING_CALCULATOR_H
#include "StringCalculator.h"

int add(const char* input) {
    if (strcmp(input, "") == 0) {
        return 0;
    }

    char* delimiters = ",\n";
    char* numbers[100];
    int count = 0;
    int sum = 0;
    int negativeCount = 0;
    char negatives[100] = "";

    // Check for custom delimiter
    if (input[0] == '/' && input[1] == '/') {
        char* delimiterEnd = strchr(input, '\n');
        if (delimiterEnd != NULL) {
            int delimiterLength = delimiterEnd - input - 2;
            delimiters = (char*)malloc(delimiterLength + 2);
            strncpy(delimiters, input + 2, delimiterLength);
            delimiters[delimiterLength] = '\0';
            delimiters[delimiterLength + 1] = '\0'; // Null-terminate the string
            input = delimiterEnd + 1;
        }
    }

    // Tokenize the input using the defined delimiters
    char* token = strtok((char*)input, delimiters);
    while (token != NULL) {
        int number = atoi(token);
        if (number < 0) {
            negativeCount++;
            if (strlen(negatives) > 0) {
                strcat(negatives, ",");
            }
            strcat(negatives, token);
        }
        if (number <= 1000) {
            sum += number;
        }
        count++;
        token = strtok(NULL, delimiters);
    }

    if (negativeCount > 0) {
        char errorMessage[256];
        snprintf(errorMessage, sizeof(errorMessage), "negatives not allowed: %s", negatives);
        fprintf(stderr, "%s\n", errorMessage);
        exit(EXIT_FAILURE);
    }

    return sum;
}
