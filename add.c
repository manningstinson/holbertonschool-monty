#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void add(stack_t **stack) {
    if (*stack && (*stack)->next) {
        (*stack)->next->n += (*stack)->n;
        pop(stack);
    } else {
        fprintf(stderr, "L%zu: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
