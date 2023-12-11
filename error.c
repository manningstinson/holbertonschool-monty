#include "monty.h"

void exit_error(int errcode, char *filename, const char *format, ...) __attribute__((format(printf, 3, 4)));

void exit_error(int errcode, char *filename, const char *format, ...) {
    (void)errcode; // Unused, preventing a warning
    (void)filename; // Unused, preventing a warning

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
    }

    if (format) {
        vprintf(format, args);
    }

    va_end(args);
    exit(errcode);
}
