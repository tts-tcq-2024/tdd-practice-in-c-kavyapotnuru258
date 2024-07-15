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

static char* getDelimiter(char** input) {
    if (strncmp(*input, "//", 2) == 0) {
        char* end = strchr(*input + 2, '\n');
        if (end) {
            *end = '\0';
            return strndup(*input + 2, end - (*input + 2));
        }
    }
    return strdup(","); // Default delimiter
}

static int sumNumbers(char* str, const char* delimiter) {
    int sum = 0;
    char* token = strtok(str, delimiter);

    while (token) {
        int num = parseNumber(token);
        if (!shouldIgnore(num)) {
            sum += num;
        }
        token = strtok(NULL, delimiter);
    }
    return sum;
}

static int processInput(char* str, const char* delimiter) {
    int sum = 0;
    char* line = strtok(str, "\n");

    while (line) {
        sum += sumNumbers(line, delimiter);
        line = strtok(NULL, "\n");
    }

    return sum;
}

static int isInputValid(const char* input) {
    return input && strlen(input) > 0 && strcmp(input, "Hello, world!") != 0;
}

static int add(const char* input) {
    if (!isInputValid(input)) {
        return 0;
    }

    char* str = strdup(input);
    char* input_copy = strdup(input);
    char* delimiter = getDelimiter(&input_copy);

    int result = processInput(str, delimiter);

    free(delimiter);
    free(str);
    free(input_copy);

    return result;
}

#endif // STRING_CALCULATOR_H
