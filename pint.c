#include "monty.h"
#include <stdio.h>

void pint(stack_t **stack) {
    if (*stack) {
        printf("%d\n", (*stack)->data);
    } else {
        fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
}

