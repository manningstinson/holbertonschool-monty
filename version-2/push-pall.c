#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *str;

	if (!stack)
		exit_error(EXIT_FAILURE, NULL, "L%u: can't push to NULL stack\n",
			line_number);

	str = strtok(NULL, " \t\n");
	if (!str || sscanf(str, "%d", &value) != 1)
		exit_error(EXIT_FAILURE, NULL, "L%u: usage: push integer\n",
			line_number);

	stack_push(*stack, value);
}

void pall(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		return;

	stack_print(*stack);
}
