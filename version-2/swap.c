#include "monty.h"

int swap(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (!*stack || !(*stack)->next) {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't swap, stack too short\n",
            line_number);
        return EXIT_FAILURE;
    }

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next->prev = *stack;
    tmp->prev = NULL;
    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = tmp;

    return EXIT_SUCCESS;
}
