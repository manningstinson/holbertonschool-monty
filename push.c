#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

void push(stack_t **stack, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = *stack;
    *stack = new_node;
}

