#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(stack_t **stack, unsigned int line_number) {
    (void)line_number; // Unused parameter, added to suppress the warning

    char *str = NULL; /* Initialize str */

    if (!stack) {
        exit_error(EXIT_FAILURE, NULL, "L%u: can't push to NULL stack\n", line_number);
    }

    str = strtok(NULL, " \t\n");
    if (!str) {
        exit_error(EXIT_FAILURE, NULL, "L%u: usage: push integer\n", line_number);
    }

    int value;
    if (sscanf(str, "%d", &value) != 1) {
        exit_error(EXIT_FAILURE, NULL, "L%u: usage: push integer\n", line_number);
    }

    if (stack_overflow(*stack)) {
        exit_error(EXIT_FAILURE, NULL, "L%u: stack overflow\n", line_number);
    }

    printf("Pushing element at line %u: %d\n", line_number, value);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        exit_error(EXIT_FAILURE, NULL, "L%u: Error allocating memory\n", line_number);
    }

    new_node->n = value;
    stack_push(stack, new_node);
}
