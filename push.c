#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
