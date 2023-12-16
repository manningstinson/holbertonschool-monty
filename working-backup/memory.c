#include "monty.h"
#include <stdlib.h>  /* For malloc, free, exit */
#include <stdio.h>

/**
 * safe_malloc - Allocates memory safely.
 * @size: Size of the memory to allocate
 *
 * Return: Pointer to the allocated memory
 */
void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/**
 * free_stack - Frees the memory occupied by the stack.
 * @stack: Pointer to the stack
 */
void free_stack(stack_t *stack)
{
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

/**
 * cleanup - Cleans up the memory occupied by the stack.
 * @stack: Pointer to the stack
 */
void cleanup(stack_t *stack)
{
    free_stack(stack);
}
