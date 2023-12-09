#include "monty.h"

void add(stack_t **stack) {
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%zu: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack);
}
