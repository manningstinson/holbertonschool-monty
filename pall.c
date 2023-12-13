#include "monty.h"
#include <stdio.h>

void pall(stack_t **stack, int line_number __attribute__((unused)))
{
    stack_t *node = *stack;

    while (node)
    {
        printf("%d\n", node->n);
        node = node->next;
    }
}
