#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

extern size_t line_number;

/**
 * Data structure for a stack (or doubly linked list)
 */
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
void nop(stack_t **stack);
void free_stack(stack_t **stack);
int read_and_execute_instructions(FILE *file);
void handle_unknown_instruction(const char *opcode);


#endif /* MONTY_H */