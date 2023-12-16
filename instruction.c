#include "monty.h"
#include <stdio.h>   /* For fprintf */
#include <stdlib.h>  /* For exit */
#include <string.h>  /* For strcmp, strtok */

void opcode_dispatcher(char *line, stack_t **stack, unsigned int line_number) {
    char *opcode = strtok(line, " \t\n");

    if (!opcode) {
        return; // Ignore empty lines
    }

    if (strcmp(opcode, "push") == 0) {
        op_push(stack, line_number);
    } else if (strcmp(opcode, "pall") == 0) {
        op_pall(stack, line_number);
    } else {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

