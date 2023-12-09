#include "monty.h"

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *temp = *stack;

    /* Traverse the stack and print values */
    while (temp) {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

