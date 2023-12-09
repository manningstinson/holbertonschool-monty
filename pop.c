#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void pop(stack_t **stack) {
    if (*stack) {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    } else {
        fprintf(stderr, "L%zu: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
}
