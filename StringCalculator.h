#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>

int add(const char* numbers) {
    if (*numbers == '\0') return 0;

    // Replace newlines with commas
    char* numbers_copy = strdup(numbers);
    for (char* p = numbers_copy; *p; p++) {
        if (*p == '\n') *p = ',';
    }

    char* token = strtok(numbers_copy, ",");
    int sum = 0;

     if (strncmp(numbers_copy, "//", 2) == 0) {
        char* newline_pos = strchr(numbers_copy, '\n');
        if (newline_pos != NULL) {
            *newline_pos = '\0';
            delimiters = numbers_copy + 2;
            numbers_copy = newline_pos + 1;
        }
    }

    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, ",");
    }

    free(numbers_copy);
    return sum;
}
