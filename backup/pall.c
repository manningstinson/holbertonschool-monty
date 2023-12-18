#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_pall - Prints all the values on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty byte code file
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!stack || !(*stack))
		return;
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
