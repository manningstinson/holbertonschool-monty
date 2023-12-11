#include "monty.h"

Instruction parse_instruction(int bytecode) {
  switch (bytecode) {
    case 1: return PUSH;
    case 2: return POP;
    case 3: return PINT;
    case 4: return PALL;
    case 5: return NOP;
    case 6: return ADD;
    case 7: return SWAP;
    default: return UNKNOWN;
  }
}

