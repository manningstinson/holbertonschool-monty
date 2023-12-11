#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *node = (*stack)->next;
    node->n += (*stack)->n;
    pop(stack);
}
