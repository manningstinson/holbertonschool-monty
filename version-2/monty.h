#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Define the stack structure */
typedef struct stack_s {
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/* Define the instruction structure */
typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
stack_t *create_stack();
void push(stack_t **top, int value);
int pop(stack_t **top);
void print_stack(stack_t *top);
void free_stack(stack_t **top);
void swap(stack_t **top, unsigned int line_number);
int pint(stack_t **top, unsigned int line_number);
void pall(stack_t *top);
void nop(void);
int add(stack_t **top, unsigned int line_number);

#endif
