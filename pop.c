#include "monty.h"
#include <stdio.h>

void pop(stack_t **stack) {
    if (*stack) {
        stack_t *temp = *stack;
        *stack = temp->next;
        free(temp);
    } else {
        fprintf(stderr, "L<line_number>: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
}

