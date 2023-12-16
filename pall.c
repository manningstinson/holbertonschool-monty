#include "monty.h"
#include <stdio.h>   /* For printf */
#include <stdlib.h>  /* For EXIT_FAILURE */

void op_pall(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pall, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

