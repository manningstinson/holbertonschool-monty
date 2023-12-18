#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty byte code file.
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	int temp = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
