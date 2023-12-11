#ifndef MONTY_H
#define MONTY_H

#define INVALID_BYTECODE 1
#define STACK_UNDERFLOW 2
#define INVALID_FILE 3

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
#define PUSH_OPCODE 1
#define POP_OPCODE 2
#define PINT_OPCODE 3

/* Function declarations */
void push(stack_t **stack, int data);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number)
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack);
void free_stack(stack_t **stack);

/* Error handling function */
void exit_error(int errcode, char *filename, const char *format, ...) __attribute__((format(printf, 3, 4)));



/* Function to check for stack overflow (implementation required) */
bool stack_overflow(stack_t *stack);

/* Function to push a node onto the stack (implementation required) */
void stack_push(stack_t **stack, stack_t *node);

/* Additional function declarations */
stack_t *create_stack(void);
instruction_t parse_instruction(int bytecode);
int execute_simple_instruction(instruction_t instruction, stack_t **top, unsigned int line_number);

/* Define instruction enum without tag */
typedef enum {
  PUSH = PUSH_OPCODE,
  POP = POP_OPCODE,
  PINT = PINT_OPCODE,
  /* ... other instructions ... */
  UNKNOWN = -1
} instruction_type;


#endif
