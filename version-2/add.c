#include "monty.h"

int add(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        return EXIT_FAILURE;
    }

    stack_t *node = (*stack)->next;
    node->n += (*stack)->n;
    pop(stack);

    return EXIT_SUCCESS;
}
