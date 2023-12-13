#include "monty.h"

stack_t *create_stack(void) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        exit_error(EXIT_FAILURE, NULL, "Memory allocation error\n");
    }
    return new_node;
}


void free_stack(stack_t **stack) {
    while (*stack) {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}


bool stack_overflow(stack_t *stack __attribute__((unused))) {
     return false; 
}



void stack_push(stack_t **stack, stack_t *node) {
    if (*stack != NULL) {
        (*stack)->prev = node;
    }
    *stack = node;
}



