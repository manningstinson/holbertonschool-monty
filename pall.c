#include "monty.h"

void pall(stack_t **stack, unsigned int line_number) {
    (void)line_number;  // To silence the unused parameter warning

    stack_t *temp = *stack;

    /* Traverse the stack and print values */
    while (temp) {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

