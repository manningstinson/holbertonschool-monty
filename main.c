#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: monty <bytecode_file>\n");
    exit(1);
  }

  FILE *bytecode_file = fopen(argv[1], "r");
  if (!bytecode_file) {
    printf("Error: Could not open bytecode file '%s'\n", argv[1]);
    exit(1);
  }

  Stack *top = create_stack();

  int bytecode;
  while (fscanf(bytecode_file, "%d", &bytecode) != EOF) {
    Instruction instruction = parse_instruction(bytecode);
    if (instruction == UNKNOWN) {
      printf("Error: Unknown instruction %d\n", bytecode);
      break;
    }
    execute_instruction(instruction, top, bytecode);
  }

  free_stack(&top);
  fclose(bytecode_file);

  return 0;
}

void execute_instruction(Instruction instruction, Stack **top, int value) {
  switch (instruction) {
    case PUSH: push(top, value); break;
    case POP: {
      int result = pop(top);
      if (result != -1) {
        printf("%d\n", result);
      }
    } break;
    case PINT: {
      int result =

