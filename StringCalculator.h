#include "StringCalculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(const char* input) {
    if (strcmp(input, "") == 0) {
        return 0;
    }

    char* delimiters = ",\n";
    char* numbers[100];
    int sum = 0;
    char negatives[100] = "";

    if (input[0] == '/' && input[1] == '/') {
        char* delimiterEnd = strchr(input, '\n');
        if (delimiterEnd != NULL) {
            size_t delimiterLength = delimiterEnd - input - 2;
            delimiters = (char*)malloc(delimiterLength + 2);
            strncpy(delimiters, input + 2, delimiterLength);
            delimiters[delimiterLength] = '\0';
            input = delimiterEnd + 1;
        }
    }

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
