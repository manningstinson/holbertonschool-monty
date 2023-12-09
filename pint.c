#include "monty.h"
#include <stdio.h>

void pint(stack_t **stack) {
    if (!stack || !*stack) {
        fprintf(stderr, "L%zu: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
