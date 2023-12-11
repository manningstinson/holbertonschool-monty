#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "stack.h"
#include "instruction.h"

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
