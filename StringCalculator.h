#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parseNumber(const char* token) {
    return atoi(token);
}

static int shouldIgnore(int num) {
    return num > 1000;
}

static char** getDelimiters(char** input) {
    char** delimiters = (char**)malloc(2 * sizeof(char*));
    delimiters[0] = strdup(","); // Default delimiter
    delimiters[1] = NULL;

    if (strncmp(*input, "//", 2) == 0) {
        char* end = strchr(*input + 2, '\n');
        if (end) {
            *end = '\0';
            delimiters[0] = strndup(*input + 2, end - (*input + 2));
            *input = end + 1; // Skip to numbers
        }
    }
    return delimiters;
}

static int processToken(char* token) {
    int num = parseNumber(token);
    return shouldIgnore(num) ? 0 : num; // Return 0 if ignored
}

static int sumNumbers(char* str, char** delimiters) {
    int sum = 0;
    char* token = strtok(str, delimiters[0]);
    
    while (token != NULL) {
        char* subtoken = strtok(token, "\n");
        while (subtoken != NULL) {
            sum += processToken(subtoken);
            subtoken = strtok(NULL, "\n");
        }
        token = strtok(NULL, delimiters[0]);
    }
    return sum;
}

static int add(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return 0;
    }

    char* str = strdup(input);
    char* input_copy = strdup(input);
    char** delimiters = getDelimiters(&input_copy);
    
    int result = sumNumbers(str, delimiters);
    
    free(delimiters[0]);
    free(delimiters);
    free(str);
    free(input_copy);
    
    return result;
}

#endif // STRING_CALCULATOR_H
