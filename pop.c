#include "monty.h"
#include <stdio.h>

/**
 * op_pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void op_pop(stack_t **stack, unsigned int line_number) {
    if (!stack || !(*stack)) {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
}
