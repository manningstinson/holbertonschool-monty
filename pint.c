#include "monty.h"
#include <stdio.h>

void pint(stack_t **stack) {
    if (*stack) {
        printf("%d\n", (*stack)->data);
    } else {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}

