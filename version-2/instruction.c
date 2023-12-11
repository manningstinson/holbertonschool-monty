#include "monty.h"

instruction_t parse_instruction(char *opcode) {
  instruction_t instruction;

  /* Map string opcodes to instruction structures */
  if (strcmp(opcode, "push") == 0) {
    instruction.opcode = "push";
    instruction.f = &push;
  } else if (strcmp(opcode, "pop") == 0) {
    instruction.opcode = "pop";
    instruction.f = &pop;
  } else if (strcmp(opcode, "pint") == 0) {
    instruction.opcode = "pint";
    instruction.f = &pint;
  } else if (strcmp(opcode, "pall") == 0) {
    instruction.opcode = "pall";
    instruction.f = &pall;
  } else if (strcmp(opcode, "nop") == 0) {
    instruction.opcode = "nop";
    instruction.f = &nop;
  } else if (strcmp(opcode, "add") == 0) {
    instruction.opcode = "add";
    instruction.f = &add;
  } else if (strcmp(opcode, "swap") == 0) {
    instruction.opcode = "swap";
    instruction.f = &swap;
  } else {
    // Handle unknown instruction
    instruction.opcode = "unknown";
    instruction.f = NULL;
  }

  return instruction;
}
