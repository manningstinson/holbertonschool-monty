#include "monty.h"
#include <stdio.h>

stack_t *create_stack(void) {
  return malloc(sizeof(stack_t));
}

void push(stack_t **stack, int data) {
  stack_t *new_node = malloc(sizeof(stack_t));

  if (!new_node) {
    exit_error(EXIT_FAILURE, NULL, "Error: malloc failed\n");
  }

  new_node->n = data;
  new_node->prev = NULL;
  new_node->next = *stack;

  if (*stack) {
    (*stack)->prev = new_node;
  }

  *stack = new_node;
}

void pall(stack_t **stack) {
  stack_t *node = *stack;

  while (node) {
    printf("%d\n", node->n);
    node = node->next;
  }
}

void pint(stack_t **stack, unsigned int line_number) {
  if (!*stack) {
    exit_error(EXIT_FAILURE, NULL, "L%u: can't pint, stack empty\n", line_number);
  }

  printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number) {
  if (!*stack) {
    exit_error(EXIT_FAILURE, NULL, "L%u: can't pop, stack empty\n", line_number);
  }

  stack_t *node = *stack;
  *stack = (*stack)->next;

  if (*stack) {
    (*stack)->prev = NULL;
  }

  free(node);
}

void swap(stack_t **stack, unsigned int line_number) {
  if (!*stack || !(*stack)->next) {
    exit_error(EXIT_FAILURE, NULL, "L%u: can't swap, stack too short\n", line_number);
  }

  stack_t *tmp = (*stack)->next;
  (*stack)->next = tmp->next;
  tmp->next = *stack;
  (*stack)->prev = tmp;
  tmp->prev = NULL;
  *stack = tmp;
}

void free_stack(stack_t **stack) {
  while (*stack) {
    stack_t *node = *stack;
    *stack = (*stack)->next;
    free(node);
  }
}
