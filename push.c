#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include <stdio.h>

void push_stack(stack_t **stack, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        cleanup(*stack);
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

int is_numeric(const char *str) {
    if (!str || (*str == '-' && *(str + 1) == '\0'))
        return 0;

    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

void op_push(stack_t **stack, unsigned int line_number) {
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_numeric(arg)) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        cleanup(*stack);
        exit(EXIT_FAILURE);
    }

    push_stack(stack, atoi(arg));
}
