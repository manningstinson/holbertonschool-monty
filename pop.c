#include "monty.h"

void pop(stack_t **stack, int line_number)
{
    if (!stack)
    {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't pop NULL stack\n", line_number);
    }

    if (!*stack)
    {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't pop an empty stack\n", line_number);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;

    if (*stack)
    {
        (*stack)->prev = NULL;
    }

    free(temp);
}
