#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>  // Include for isdigit

void op_push(stack_t **stack, unsigned int line_number) {
    /* Existing code */

    if (!arg) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Check if arg is a valid integer */
    for (size_t i = 0; i < strlen(arg); i++) {
        if (!isdigit(arg[i]) && !(i == 0 && arg[i] == '-')) {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    int value = atoi(arg);
    /* Rest of your code */
}
