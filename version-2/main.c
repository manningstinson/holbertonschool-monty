#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: monty <bytecode_file>\n");
    exit(EXIT_FAILURE);
  }

  FILE *bytecode_file = fopen(argv[1], "r");
  if (!bytecode_file) {
    fprintf(stderr, "Error: Could not open bytecode file '%s'\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  Stack *top = create_stack();

  int bytecode;
  unsigned int line_number = 0;
  while (fscanf(bytecode_file, "%d", &bytecode) != EOF) {
    line_number++;
    Instruction instruction = parse_instruction(bytecode);
    if (instruction == UNKNOWN) {
      exit_error(EXIT_FAILURE, NULL, "L%u: Unknown instruction '%d'\n",
                  line_number, bytecode);
    }

    execute_instruction(instruction, &top, line_number, bytecode);
  }

  free_stack(&top);
  fclose(bytecode_file);

  return EXIT_SUCCESS;
}

void execute_instruction(Instruction instruction, Stack **top, unsigned int line_number, int value) {
  int result;

  switch (instruction) {
    case PUSH:
      push(top, value);
      break;
    case POP:
      result = pop(top);
      if (result != -1) {
        printf("%d\n", result);
      }
      break;
    case PINT:
      result = pint(top, line_number);
      if (result != EXIT_SUCCESS) {
        exit(EXIT_FAILURE);
      }
      break;
    // Add similar cases for other instructions
    default:
      exit_error(EXIT_FAILURE, NULL, "L%u: Unknown instruction\n", line_number);
  }
}
