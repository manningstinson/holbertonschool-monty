#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int read_file(char *filename, stack_t **stack) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1) {
        line_number++;
        opcode_dispatcher(line, stack, line_number);
    }

    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}
