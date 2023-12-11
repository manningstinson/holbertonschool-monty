#include "monty.h"

#include <stdlib.h>
#include <string.h>

/* Define a struct for mapping opcodes to functions and error messages */
typedef struct opcode_mapping {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
  char *error_msg;
} opcode_mapping_t;

/* Create an array of opcode mappings */
opcode_mapping_t opcode_map[] = {
  {"push", &push, "Invalid input format for push"},
  {"pop", &pop, "Stack underflow"},
  {"pint", &pint, "Stack underflow"},
  {"pall", &pall, NULL},
  {"nop", &nop, NULL},
  {"add", &add, "Stack underflow"},
  {"swap", &swap, "Stack too short"},
  // Add more mappings for new opcodes
  // ...
  {NULL, NULL, "Unknown instruction"}
};

instruction_t parse_instruction(char *opcode) {
  instruction_t instruction;

  /* Use a hash table for faster lookup (optional) */
  // ...

  /* Linear search through the opcode map */
  for (int i = 0; opcode_map[i].opcode; i++) {
    if (strcmp(opcode, opcode_map[i].opcode) == 0) {
      instruction.opcode = opcode_map[i].opcode;
      instruction.f = opcode_map[i].f;
      return instruction;
    }
  }

  /* Handle unknown opcode */
  instruction.opcode = opcode_map[i].opcode;
  instruction.f = NULL;
  fprintf(stderr, "L%u: %s\n", line_number, opcode_map[i].error_msg);
  exit(EXIT_FAILURE);
}
