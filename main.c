#include "monty.h"
#include <string.h>

size_t line_number = 1;

int read_and_execute_instructions(FILE *file) {
    char opcode[256];
    int value;
    stack_t *stack = NULL;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            /* Handle push instruction */
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%zu: usage: push integer\n", line_number);
                return 0;  /* Failed execution */
            }
            push(&stack, value);
        } else if (strcmp(opcode, "pint") == 0) {
            /* Handle pint instruction */
            pint(&stack);
        } else if (strcmp(opcode, "pall") == 0) {
            /* Handle pall instruction */
            pall(&stack);
        } else {
            /* Handle unknown command */
            fprintf(stderr, "L%zu: unknown instruction %s\n", line_number, opcode);
        }

        // Read and discard the rest of the line
        while (fgetc(file) != '\n');

        line_number++;
    }

    /* Free allocated memory and perform any cleanup if needed */
    free(stack);

    return 1;  /* Successful execution */
}
