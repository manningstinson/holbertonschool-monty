#include "monty.h"
#include <stdlib.h>  /* For malloc, free, EXIT_FAILURE */
#include <stdio.h>   /* For FILE, fopen, fprintf, fclose */

int read_file(char *filename, stack_t **stack) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;

        if (*line == '\n' || *line == '#') {
            // Ignore blank lines and comments
            continue;
        }

        opcode_dispatcher(line, stack, line_number);
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}

