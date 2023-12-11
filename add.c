#include "monty.h"

void add(stack_t **stack) {
  if (!*stack || !(*stack)->next) {
    exit_error(EXIT_FAILURE, NULL, "L%u: can't add, stack too short\n", line_number);
  }

  stack_t *node = (*stack)->next;
  node->n += (*stack)->n;
  pop(stack);
}
