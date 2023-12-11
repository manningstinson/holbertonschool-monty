#ifndef MONTY_H
#define MONTY_H

#include <stdio.h> /* Necessary for standard input/output functions */
#include <stdlib.h> /* Necessary for memory allocation and other utilities */

/*
 * Structure representing a node in the stack.
 *
 * @n: The integer value stored in the node.
 * @prev: Pointer to the previous node in the stack.
 * @next: Pointer to the next node in the stack.
 */
typedef struct stack_s {
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/*
 * Structure representing an instruction.
 *
 * @opcode: The opcode string for the instruction.
 * @f: Function pointer to the function that handles the instruction.
 */
typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*
 * Function prototypes:
 *
 * create_stack(): Creates and initializes a new stack.
 * push(top, value): Pushes a value onto the stack.
 * pop(top): Pops a value from the stack and returns it.
 * print_stack(top): Prints all elements in the stack.
 * free_stack(top): Frees the memory allocated for the stack.
 * swap(top, line_number): Swaps the top two elements of the stack.
 * pint(top, line_number): Prints the top element of the stack and removes it.
 * pall(top): Prints all elements in the stack from top to bottom.
 * nop(): Does nothing.
 * add(top, line_number): Adds the top two elements of the stack and stores the result in the second top element.
 */
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
