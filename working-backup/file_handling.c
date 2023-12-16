#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * read_file - Reads the content of a file and executes Monty byte codes.
 * @filename: Name of the file to read
 * @stack: Double pointer to the stack
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int read_file(char *filename, stack_t **stack)
{
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        /* Remove newline character at the end of the line */
        size_t line_len = strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n')
            line[line_len - 1] = '\0';

        /* Process the line and execute Monty byte codes */
        opcode_dispatcher(line, stack, line_number);
    }

    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}
