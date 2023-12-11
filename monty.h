#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>

typedef struct stack_s {
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define PUSH 1
#define POP 2
#define PINT 3

void push(stack_t **stack, int data);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void nop(stack_t **stack);
void free_stack(stack_t **stack);

#endif
