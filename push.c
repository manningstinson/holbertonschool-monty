#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(stack_t **stack, unsigned int line_number) {
    (void)line_number; // Unused parameter, added to suppress the warning

    char *str = strtok(NULL, " \t\n");
    if (!str) {
        exit_error(EXIT_FAILURE, NULL, "L%u: usage: push integer\n", line_number);
    }

    // Ensure the entire string is a valid integer
    char *endptr;
    int value = strtol(str, &endptr, 10);

    if (*endptr != '\0' && *endptr != '\n') {
        exit_error(EXIT_FAILURE, NULL, "L%u: usage: push integer\n", line_number);
    }

    printf("Pushing element at line %u: %d\n", line_number, value);

    // Rest of your push logic...
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        exit_error(EXIT_FAILURE, NULL, "L%u: Error allocating memory for stack node\n", line_number);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
