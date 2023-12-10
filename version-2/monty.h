#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
typedef struct Stack {
  int value;   // Data value stored in the stack
  struct Stack *next;  // Pointer to the next element in the stack
} Stack;

// Define an enum for different instructions
typedef enum Instruction {
  PUSH,      // Push value onto the stack
  POP,       // Pop value from the stack
  PINT,      // Print the top value of the stack
  PALL,      // Print all values in the stack
  NOP,       // No operation
  ADD,       // Add two top values of the stack
  UNKNOWN    // Unknown instruction
} Instruction;

// Function prototypes
Stack *create_stack();
void push(Stack **top, int value);
int pop(Stack **top);
void print_stack(Stack *top);
void free_stack(Stack **top);
Instruction parse_instruction(int bytecode);


#endif

