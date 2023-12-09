#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

/* Define stack structure if not already done in monty.h */
typedef struct stack {
    int data;
    struct stack *next;
} stack_t;

/* Function prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
int read_and_execute_instructions(FILE *file);

#endif /* MONTY_H */

