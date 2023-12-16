#include "monty.h"
#include <stdio.h>

stack_t *create_stack(void) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        exit_error(EXIT_FAILURE, NULL, "Memory allocation error in create_stack\n");
    }

    new_node->n = 0;        // Initialize the value to 0 or any default value
    new_node->prev = NULL;
    new_node->next = NULL;

    printf("Created a new stack at address: %p\n", (void *)new_node);

    return new_node;
}

void free_stack(stack_t **stack) {
    while (*stack) {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
        printf("Freed a node from the stack\n");
    }
}

bool stack_overflow(stack_t *stack __attribute__((unused))) {
    return false;  // Placeholder for overflow condition; adjust as needed
}

void stack_push(stack_t **stack, stack_t *node) {
    if (*stack != NULL) {
        (*stack)->prev = node;
        node->next = *stack;
    }
    *stack = node;

    printf("Pushed a node onto the stack with value: %d\n", node->n);
}
