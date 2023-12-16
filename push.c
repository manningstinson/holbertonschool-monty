#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include <stdio.h>

/**
 * push_stack - Pushes a new node with a given value onto the stack.
 * @stack: Double pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push_stack(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
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

/**
 * is_numeric - Checks if a given string represents a numeric value.
 * @str: String to be checked
 * @value: Pointer to store the integer value
 *
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(const char *str, int *value)
{
    if (!str || (*str == '-' && *(str + 1) == '\0'))
        return 0;

    char *endptr;
    *value = strtol(str, &endptr, 10);

    return *endptr == '\0';
}

/**
 * op_push - Executes the push operation.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the Monty byte code file
 */
void op_push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        cleanup(*stack);
        exit(EXIT_FAILURE);
    }

    int value;
    if (!is_numeric(arg, &value))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        cleanup(*stack);
        exit(EXIT_FAILURE);
    }

    push_stack(stack, value);
}
