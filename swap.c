#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void swap(stack_t **stack) {
    if (*stack && (*stack)->next) {
        int temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    } else {
        fprintf(stderr, "L%zu: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
