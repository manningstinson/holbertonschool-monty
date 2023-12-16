#include "monty.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * is_numeric - Check if a string is numeric.
 * @str: The string to check.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(char *str)
{
    if (!str)
        return (0);

    if (*str == '-' && str[1] == '\0')
        return (0);

    while (*str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }

    return (1);
}

/**
 * op_push - Push an element onto the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number in the Monty file.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_numeric(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    push_stack(stack, atoi(arg));
}
