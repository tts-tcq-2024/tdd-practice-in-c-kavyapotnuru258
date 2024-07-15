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

static char* getDelimiter(const char** input) {
    if (strncmp(*input, "//", 2) == 0) {
        char* end = strchr(*input + 2, '\n');
        if (end) {
            *end = '\0';
            char* delimiter = strndup(*input + 2, end - (*input + 2));
            *input = end + 1; // Skip to numbers
            return delimiter;
        }
    }
    return strdup(",");
}

static int sumNumbers(char* str, const char* delimiter) {
    int sum = 0;
    char* token = strtok(str, delimiter);
    while (token != NULL) {
        int num = parseNumber(token);
        if (!shouldIgnore(num)) {
            sum += num;
        }
        token = strtok(NULL, delimiter);
    }
    return sum;
}

static int add(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return 0;
    }

    char* str = strdup(input);
    const char* original_input = input;
    char* delimiter = getDelimiter(&original_input);
    
    int result = sumNumbers(str, delimiter);
    free(delimiter);
    free(str);
    
    return result;
}

#endif // STRING_CALCULATOR_H
