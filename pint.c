#include <stdio.h>
#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number of the current operation.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !(*stack))
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit_error(EXIT_FAILURE, NULL, NULL);
    }

    printf("%d\n", (*stack)->n);
}
