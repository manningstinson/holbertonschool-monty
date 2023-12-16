#include <stdio.h>
#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit_error(EXIT_FAILURE, NULL, NULL);
    }

    printf("%d\n", (*stack)->n);
}