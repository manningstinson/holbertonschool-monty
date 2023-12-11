#include "monty.h"

void pall(stack_t **stack) {
    stack_t *current = *stack;

    while (current) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
