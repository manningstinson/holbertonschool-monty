#include "monty.h"

Instruction parse_instruction(int bytecode) {
  switch (bytecode) {
    case 1: return PUSH;
    case 2: return POP;
    case 3: return PINT;
    case 4: return PALL;
    case 5: return NOP;
    case 6: return ADD;
    default: return UNKNOWN;
  }
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
      int result = pop(top);
      if (result != -1) {
        printf("%d\n", result);
        // You might want to push the value back onto the stack if needed.
      }
    } break;
    // Add cases for other instructions as needed
    default:
      // Handle unknown instructions or other cases
      break;
  }
}
