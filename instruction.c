#include "monty.h"

instruction_t parse_instruction(int bytecode) {
    instruction_t instruction;

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
        // Add other cases for different opcodes
        default:
            instruction.opcode = "unknown";
            instruction.f = nop;  // Default to no operation
            break;
    }

    return instruction;
}

#include "monty.h"

int execute_simple_instruction(instruction_t instruction, stack_t **top, unsigned int line_number) {
    instruction.f(top, line_number);
    return 0;  
}
