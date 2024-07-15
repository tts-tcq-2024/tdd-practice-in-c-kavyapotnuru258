#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int add(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return 0;
    }

    char* str = strdup(input);
    char* delimiter = ",";
    int sum = 0;
    int num;

    // Check for custom delimiter
    if (strncmp(str, "//", 2) == 0) {
        char* end = strchr(str + 2, '\n');
        if (end) {
            *end = '\0';
            delimiter = str + 2;  // Custom delimiter
            str = end + 1;         // Skip to numbers
        }
    }

    // Tokenize the input string
    char* token = strtok(str, delimiter);
    while (token != NULL) {
        num = atoi(token);
        if (num > 1000) {
            token = strtok(NULL, delimiter);
            continue; // Ignore numbers greater than 1000
        }
        sum += num;
        token = strtok(NULL, delimiter);
    }

    free(str);
    return sum;
}

#endif // STRING_CALCULATOR_H
