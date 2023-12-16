#include "monty.h"
#include <stdio.h>

int read_file(char *filename, stack_t **stack) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

    /* Rest of your code for reading the file */

    fclose(file);
    return EXIT_SUCCESS;
}
