#include "monty.h"
#include <stdio.h>

void nop(stack_t **stack, unsigned int line_number) {
    (void)stack;
    (void)line_number;
    
    // No operation (NOP) - do nothing
    printf("Executing NOP at line %u\n", line_number);
}
