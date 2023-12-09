#include "monty.h"

void push(stack_t **stack, unsigned int line_number) {
    char *arg;
    int value;

    /* Check if there's an argument */
    if (!stack || !line_number) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Get the argument after push */
    arg = strtok(NULL, " \t\n");

    /* Check if there's an actual argument */
    if (!arg || !isdigit(*arg) && *arg != '-' && *arg != '+') {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert string to integer using atoi */
    value = atoi(arg);

    /* Allocate memory for a new node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Update new node with value and link to the current stack */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous node's prev pointer if the stack is not empty */
    if (*stack)
        (*stack)->prev = new_node;

    /* Update the stack to point to the new node */
    *stack = new_node;
}

