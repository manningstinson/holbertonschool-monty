#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char **argv) {
  /* Check for correct number of arguments */
  if (argc != 2) {
    printf("Usage: monty <bytecode_file>\n");
    exit(EXIT_FAILURE);
  }

  /* Open the bytecode file */
  FILE *bytecode_file = fopen(argv[1], "r");
  if (!bytecode_file) {
    fprintf(stderr, "Error: Could not open bytecode file '%s'\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  /* Create the stack */
  stack_t *top = create_stack();

  /* Read and execute instructions */
  int bytecode;
  unsigned int line_number = 0;
  while (fscanf(bytecode_file, "%d", &bytecode) != EOF) {
    line_number++;

    /* Parse the instruction */
    Instruction instruction = parse_instruction(bytecode);
    if (instruction == UNKNOWN) {
      exit_error(EXIT_FAILURE, NULL, "L%u: Unknown instruction '%d'\n",
                  line_number, bytecode);
    }

    /* Execute the instruction */
    int result = EXIT_SUCCESS;
    switch (instruction) {
      case PUSH:
        push(top, bytecode);
        break;
      case POP:
      case PINT:
        result = execute_simple_instruction(instruction, top, line_number);
        break;
      // Add similar cases for other instructions
      default:
        exit_error(EXIT_FAILURE, NULL, "L%u: Unknown instruction\n", line_number);
    }

    if (result != EXIT_SUCCESS) {
      exit(EXIT_FAILURE);
    }
  }

  /* Free resources and exit */
  free_stack(&top);
  fclose(bytecode_file);

  return EXIT_SUCCESS;
}

/*
 * Handles simple instructions like POP and PINT which require similar
 * error checking logic.
 */
int execute_simple_instruction(Instruction instruction, stack_t **top, unsigned int line_number) {
  int result = -1;

  switch (instruction) {
    case POP:
      result = pop(top);
      break;
    case PINT:
      result = pint(top, line_number);
      break;
    // Add similar cases for other simple instructions
  }

  if (result == -1) {
    exit_error(EXIT_FAILURE, NULL, "L%u: Error executing instruction '%s'\n", line_number, instruction.opcode);
  }

  return EXIT_SUCCESS;
}
