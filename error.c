#include "monty.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void exit_error(int errcode, const char *format, ...) {
    va_list args;
    va_start(args, format);

    switch (errcode) {
        case INVALID_BYTECODE:
            printf("Error: Unknown instruction\n");
            break;
        case STACK_UNDERFLOW:
            printf("Error: Stack underflow\n");
            break;
        case INVALID_FILE:
            printf("Error: Could not open bytecode file\n");
            break;
        /* Add cases for other error types */
        default:
            printf("Error: Unknown error code\n");
            break;
    }

    if (format) {
        vprintf(format, args);
    }

    va_end(args);
    exit(errcode);
}
