#include "monty.h"
#include <stdio.h>

void handle_malloc_error(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

void handle_unknown_instruction(const char *opcode) {
    fprintf(stderr, "L%zu: unknown instruction %s\n", line_number, opcode);
}
