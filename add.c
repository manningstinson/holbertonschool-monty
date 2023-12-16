#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty byte code file
 */
void op_add(stack_t **stack, unsigned int line_number) {
    if (!stack || !*stack || !(*stack)->next) {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    op_pop(stack, line_number);  // Remove the top element
}
