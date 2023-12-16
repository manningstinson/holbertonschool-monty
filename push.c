#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_numeric - Checks if a string is numeric
 * @str: String to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(char *str) {
    if (!str || *str == '\0')
        return 0;

    for (; *str; ++str) {
        if (*str == '-' && str == str)
            continue;
        if (!isdigit(*str))
            return 0;
    }

    return 1;
}

/**
 * op_push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty byte code file
 */
void op_push(stack_t **stack, unsigned int line_number) {
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_numeric(arg)) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    push_stack(stack, atoi(arg));
}
