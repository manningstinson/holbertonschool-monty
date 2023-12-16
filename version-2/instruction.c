#include "monty.h"
#include <stdio.h>


instruction_t parse_instruction(int bytecode) 
{
    instruction_t instruction;

    printf("Parsing Bytecode: %d\n", bytecode); // Debugging statement

    switch (bytecode) {
        case PUSH_OPCODE:
            instruction.opcode = "push";
            instruction.f = push;
            break;
        case POP_OPCODE:
            instruction.opcode = "pop";
            instruction.f = pop;
            break;
        case PINT_OPCODE:
            instruction.opcode = "pint";
            instruction.f = pint;
            break;
        case PALL_OPCODE:
            instruction.opcode = "pall";
            instruction.f = pall;
            break;
        case ADD_OPCODE:
            instruction.opcode = "add";
            instruction.f = add;
            break;
        case NOP_OPCODE:
            instruction.opcode = "nop";
            instruction.f = nop;
            break;
        // Add other cases for different opcodes
        default:
            instruction.opcode = "unknown";
            instruction.f = nop;  // Default to no operation
            break;
    }

    printf("Parsed Opcode: %s\n", instruction.opcode); // Debugging statement

    return instruction;
}
