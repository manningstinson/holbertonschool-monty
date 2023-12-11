#ifndef MONTY_H
#define MONTY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/* Stack node structure */
typedef struct stack_s {
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/* Instruction structure */
typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, int data);
} instruction_t;

/* Opcodes */
#define PUSH 1
#define POP 2
#define PINT 3

/* Function declarations */
void push(stack_t **stack, int data);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack);
void free_stack(stack_t **stack);

/* Error handling function */
void exit_error(int status, char *file, char *format, ...);

/* Function to check for stack overflow (implementation required) */
bool stack_overflow(stack_t *stack);

/* Function to push a node onto the stack (implementation required) */
void stack_push(stack_t **stack, stack_t *node);

/* Additional function declarations */
stack_t *create_stack(void);
instruction_t parse_instruction(int bytecode);
int execute_simple_instruction(instruction_t instruction, stack_t **top, unsigned int line_number);

/* Define instruction enum without tag */
enum {
  PUSH,
  POP,
  PINT,
  /* ... other instructions ... */
  UNKNOWN = -1
};

#endif
