#include "monty.h"
#include <stdio.h>

void swap(stack_t **stack) {
    if (*stack && (*stack)->next) {
        int temp = (*stack)->data;
        (*stack)->data = (*stack)->next->data;
        (*stack)->next->data = temp;
    } else {
        fprintf(stderr, "L<line_number>: can't swap, stack too short\n");
        exit(EXIT_FAILURE);
    }
}

