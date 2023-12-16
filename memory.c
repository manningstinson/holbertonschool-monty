#include "monty.h"
#include <stdlib.h>  /* For malloc, free, exit */
#include <stdio.h>

void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_stack(stack_t *stack) {
    while (stack != NULL) {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

void cleanup(stack_t *stack) {
    free_stack(stack);
}

