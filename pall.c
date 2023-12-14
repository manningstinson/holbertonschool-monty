#include "monty.h"
#include <stdio.h>

void pall(stack_t **stack, unsigned int line_number) {
    (void)line_number; // Unused parameter, added to suppress the warning

    if (*stack == NULL) {
        return; // If the stack is empty, do nothing
    }

    stack_t *current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
