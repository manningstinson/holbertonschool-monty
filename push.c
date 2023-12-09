// push.c

#include "monty.h"

void push(stack_t **stack, unsigned int line_number) {
    char *arg;
    int value;

    if (!stack) {
        fprintf(stderr, "L%u: stack not found\n", line_number);
        exit(EXIT_FAILURE);
    }

    arg = strtok(NULL, " \t\n");

    if (!arg || (*arg != '-' && *arg != '+' && !isdigit(*arg))) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int len = strlen(arg);
    for (int i = 0; i < len; i++) {
        if (!isdigit(arg[i]) && !(i == 0 && (arg[i] == '-' || arg[i] == '+'))) {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    value = atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
