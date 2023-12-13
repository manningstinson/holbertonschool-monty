#include <stdio.h>
#include "monty.h"

void swap(stack_t **stack, int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't swap, stack too short\n", line_number);
    }

    stack_t *tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;
}
