#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include <stdio.h>

/**
 * push_stack - Pushes a new node with a given value onto the stack.
 * @stack: Double pointer to the stack
 * @value: Value to be pushed onto the stack
 *
 * This function creates a new node with the specified value and adds it to the
 * top of the stack. If the allocation of memory fails, an error message is
 * printed, and the program exits.
 */
void push_stack(stack_t **stack, int value)
{
    printf("Debug: Entering push_stack\n");

    /* Allocate memory for a new node */
    stack_t *new_node = malloc(sizeof(stack_t));

    /* Check for memory allocation failure */
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        cleanup(*stack);
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node with the provided value */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous pointer of the previous top node */
    if (*stack)
        (*stack)->prev = new_node;

    /* Update the stack pointer to point to the new top node */
    *stack = new_node;

    printf("Debug: push_stack completed successfully\n");
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
    printf("Debug: Entering is_numeric\n");

    if (!str || (*str == '-' && *(str + 1) == '\0'))
        return (0);

    char *endptr;

    /* Convert the string to an integer and store it in value */
    *value = strtol(str, &endptr, 10);

    /* Check if the conversion was successful */
    int is_numeric = (*endptr == '\0');

    printf("Debug: is_numeric completed successfully\n");

    return is_numeric;
}

/**
 * op_push - Executes the push operation.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the Monty byte code file
 *
 * This function extracts the argument from the command and pushes it onto the stack.
 * If the argument is missing or not a valid integer, an error message is printed,
 * and the program exits.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
    printf("Debug: Entering op_push\n");

    /* Extract the argument from the command */
    char *arg = strtok(NULL, " \t\n");

    /* Check if the argument is missing */
    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        cleanup(*stack);
        exit(EXIT_FAILURE);
    }

    printf("Debug: Argument received: %s\n", arg);

    int value;

    /* Check if the argument is a valid integer */
    if (!is_numeric(arg, &value))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        cleanup(*stack);
        exit(EXIT_FAILURE);
    }

    printf("Debug: Numeric value extracted: %d\n", value);

    /* Push the numeric value onto the stack */
    push_stack(stack, value);

    printf("Debug: op_push completed successfully\n");
}
