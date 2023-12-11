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
    instruction_t instruction = parse_instruction(bytecode);

    /* Check for unknown instruction */
if (strcmp(instruction.opcode, "UNKNOWN") == 0) {
  exit_error(EXIT_FAILURE, NULL, "L%u: Unknown instruction '%s'\n",
              line_number, instruction.opcode);
}


    /* Execute the instruction */
    int result = execute_simple_instruction(instruction, &top, line_number);

