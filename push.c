#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty byte code file
 */
void op_push(stack_t **stack, unsigned int line_number) {
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_numeric(arg)) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    push_stack(stack, atoi(arg));
}

/**
 * is_numeric - Checks if a string is a numeric value
 * @str: String to check
 *
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(char *str) {
    if (!str || *str == '\0' || *str == '\n')
        return 0;

    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;

    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}
