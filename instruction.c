#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * opcode_dispatcher - Executes Monty bytecode instructions.
 * @line: Line containing opcode and arguments.
 * @stack: Double pointer to the stack.
 * @line_number: Current line number in the Monty file.
 *
 * Description: Parses input line to determine opcode and
 * dispatches corresponding Monty operation using the stack.
 * Supports "push," "pall," "pint," "pop," and "swap" opcodes.
 *
 * Return: None.
 */
void opcode_dispatcher(char *line, stack_t **stack, unsigned int line_number) {
    char *opcode = strtok(line, " \t\n");

    if (!opcode) {
        return; // Ignore empty lines
    }

    if (strcmp(opcode, "push") == 0) {
        op_push(stack, line_number);
    } else if (strcmp(opcode, "pall") == 0) {
        op_pall(stack, line_number);
    } else if (strcmp(opcode, "pint") == 0) {
        op_pint(stack, line_number);
    } else if (strcmp(opcode, "pop") == 0) {
        op_pop(stack, line_number);
    } else if (strcmp(opcode, "swap") == 0) {
        op_swap(stack, line_number);
    } else {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
