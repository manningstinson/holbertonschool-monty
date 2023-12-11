#include "monty.h"

int pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack) {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't pint, stack empty\n",
            line_number);
        return EXIT_FAILURE;
    }

    printf("%d\n", (*stack)->n);
    pop(stack);

    return EXIT_SUCCESS;
}
