#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include the string.h library

extern size_t line_number;

typedef struct stack_s {
    int data;
    struct stack_s *next;
} stack_t;

/* Function prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
int read_and_execute_instructions(FILE *file);
void free_stack(stack_t **stack);

#endif /* MONTY_H */
