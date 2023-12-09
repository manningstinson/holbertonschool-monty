#include "monty.h"

void swap(stack_t **stack) {
    if (*stack && (*stack)->next) {
        int temp = (*stack)->data;  // Change 'n' to 'data'
        (*stack)->data = (*stack)->next->data;
        (*stack)->next->data = temp;
    } else {
        fprintf(stderr, "L%zu: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}
