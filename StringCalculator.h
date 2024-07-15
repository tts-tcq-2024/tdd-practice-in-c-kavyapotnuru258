#include "StringCalculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>

int add(const char* input) {
    if (strcmp(input, "") == 0) {
        return 0;
    }

    const char* delimiters = ",\n";
    char* normalizedInput = strdup(input); // Duplicate input for tokenization
    char* customDelimiter = NULL;

    // Check for custom delimiter
    if (strncmp(normalizedInput, "//", 2) == 0) {
        char* delimiterEnd = strchr(normalizedInput, '\n');
        if (delimiterEnd) {
            *delimiterEnd = '\0'; // Null-terminate the custom delimiter
            customDelimiter = normalizedInput + 2;
            delimiters = customDelimiter;
            normalizedInput = delimiterEnd + 1;
        }
    }

    // Replace newlines with commas
    for (char* p = normalizedInput; *p; p++) {
        if (*p == '\n') *p = ',';
    }

    int sum = 0;
    char* token = strtok(normalizedInput, delimiters);
    char negatives[100] = "";

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

    free(normalizedInput); // Free the duplicated string
    return sum;
}
