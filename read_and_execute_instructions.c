#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

size_t line_number = 1;  /* Define and initialize line_number */

void free_stack(stack_t **stack) {
    while (*stack) {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

int read_and_execute_instructions(FILE *file) {
    char opcode[256];
    int value;
    stack_t *stack = NULL;
    int opcode_valid;

    while (fscanf(file, "%s", opcode) != EOF) {
        opcode_valid = 1;  /* Assume the opcode is valid initially */

        if (strcmp(opcode, "push") == 0) {
            /* Handle push instruction */
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%zu: usage: push integer\n", line_number);
                opcode_valid = 0;
            } else {
                push(&stack, value);
            }
        } else if (strcmp(opcode, "pint") == 0) {
            /* Handle pint instruction */
            pint(&stack);
        } else if (strcmp(opcode, "pall") == 0) {
            /* Handle pall instruction */
            pall(&stack);
        } else if (strcmp(opcode, "pnit") == 0) {
            /* Handle pnit as a valid instruction without affecting the stack */
            printf("%s\n", opcode);
        } else {
            /* Handle unknown command */
            opcode_valid = 0;
        }

        if (!opcode_valid) {
            fprintf(stderr, "L%zu: unknown instruction %s\n", line_number, opcode);
            free_stack(&stack);
            return 0;  /* Failed execution */
        }

        // Read and discard the rest of the line
        while (fgetc(file) != '\n');

        line_number++;
    }

    /* Free allocated memory and perform any cleanup if needed */
    free_stack(&stack);

    return 1;  /* Successful execution */
}
