#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * cleanup_wrapper - Wrapper function for atexit with the correct signature
 */
void cleanup_wrapper(void) {
    cleanup();  // Assuming cleanup takes no arguments
}

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    stack_t *stack = NULL;

    if (read_file(filename, &stack) == EXIT_FAILURE) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

    atexit(cleanup_wrapper);

    return EXIT_SUCCESS;
}
