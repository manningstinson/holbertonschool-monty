#include "monty.h"

void add(stack_t **stack) {
    if (*stack && (*stack)->next) {
        (*stack)->next->data += (*stack)->data;
        pop(stack);
    } else {
        fprintf(stderr, "L%zu: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
