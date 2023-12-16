#include "monty.h"
#include <stdlib.h>  /* For atoi, malloc, exit */
#include <ctype.h>   /* For isdigit */

void op_push(stack_t **stack, unsigned int line_number) {
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !isdigit(*arg)) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);

    stack_t *new_node = safe_malloc(sizeof(stack_t));
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

