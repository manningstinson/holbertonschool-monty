#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
    stack_t *node;

    if (!*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    node = (*stack)->next;
    node->n += (*stack)->n;
    pop(stack);
}
