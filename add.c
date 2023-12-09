#include "monty.h"
#include <stdio.h>

void add(stack_t **stack) {
    if (*stack && (*stack)->next) {
        (*stack)->next->data += (*stack)->data;
        pop(stack);  /* Remove the top element */
    } else {
        fprintf(stderr, "L<line_number>: can't add, stack too short\n");
        exit(EXIT_FAILURE);
    }
}

