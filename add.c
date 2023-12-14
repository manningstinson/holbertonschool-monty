#include "monty.h"
#include <stdio.h>

void add(stack_t **stack, unsigned int line_number) {
    if (!*stack || !(*stack)->next) {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't add, stack too short\n", line_number);
    }

    printf("Before addition: %d + %d\n", (*stack)->n, (*stack)->next->n); // Debugging statement

    stack_t *node = (*stack)->next;
    node->n += (*stack)->n;
    pop(stack, line_number);  // Pass line_number to pop function

    printf("After addition: %d\n", node->n); // Debugging statement
}
