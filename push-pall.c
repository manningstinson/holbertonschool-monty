#include "monty.h"

void push(stack_t **stack, int value) {
    char *str;

    if (!stack) {
        exit_error(EXIT_FAILURE, NULL, "can't push to NULL stack\n");
    }

    str = strtok(NULL, " \t\n");
    if (!str || sscanf(str, "%d", &value) != 1) {
        exit_error(EXIT_FAILURE, NULL, "usage: push integer\n");
    }

    if (stack_overflow(*stack)) {
        exit_error(EXIT_FAILURE, NULL, "stack overflow\n");
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        exit_error(EXIT_FAILURE, NULL, "Error allocating memory\n");
    }

    new_node->n = value;
    stack_push(stack, new_node);
}
