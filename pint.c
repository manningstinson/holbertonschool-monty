#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty byte code file
 */
void op_pint(stack_t **stack, unsigned int line_number) {
    if (!stack || !(*stack)) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("Debug: Popping value from stack: %d\n", (*stack)->n);
    printf("%d\n", (*stack)->n);
}
