#include "monty.h"
#include <stdlib.h>  /* For EXIT_FAILURE and EXIT_SUCCESS */
#include <stdio.h>   /* For fprintf */

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

    atexit(cleanup);

    return EXIT_SUCCESS;
}

