#include "monty.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void exit_error(int errcode, const char *format, ...) {
    va_list args;
    va_start(args, format);

    printf("Error Code: %d\n", errcode); // Debugging statement

    switch (errcode) {
        case INVALID_BYTECODE:
            fprintf(stderr, "Error: Unknown instruction\n");
            break;
        case STACK_UNDERFLOW:
            fprintf(stderr, "Error: Stack underflow\n");
            break;
        case INVALID_FILE:
            fprintf(stderr, "Error: Could not open bytecode file\n");
            break;
        /* Add cases for other error types */
        default:
            fprintf(stderr, "Error: Unknown error code\n");
            break;
    }

    if (format) {
        vfprintf(stderr, format, args);
    }

    va_end(args);
    exit(errcode);
}
