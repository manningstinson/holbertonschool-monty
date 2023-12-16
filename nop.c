#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_nop - Doesn't do anything.
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty byte code file
 */
void op_nop(stack_t **stack, unsigned int line_number) {
    (void)stack;
    (void)line_number;
    /* No operation, just skip */
}
