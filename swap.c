#include "monty.h"

void swap(stack_t **stack, int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't swap, stack too short\n", line_number);
        return;  // No need for return statements in a void function
    }

    /* Avoid unnecessary temporary variable */
    (*stack)->next->prev = *stack;
    (*stack)->prev = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    (*stack)->prev->next = *stack;
    *stack = (*stack)->prev;
}
