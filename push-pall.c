#include "monty.h"
#include <stdio.h> // Added header for printf and strtok

void push(stack_t **stack, int data) {
	int value;
	char *str;

	if (!stack) {
		exit_error(EXIT_FAILURE, NULL, "L%u: can't push to NULL stack\n",
			line_number);
	}

	str = strtok(NULL, " \t\n");
	if (!str || sscanf(str, "%d", &value) != 1) {
		exit_error(EXIT_FAILURE, NULL,
			"L%u: usage: push integer\n", line_number);
	}

	if (stack_overflow(*stack)) {
		exit_error(EXIT_FAILURE, NULL,
			"L%u: stack overflow\n", line_number);
	}

	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node) {
		exit_error(EXIT_FAILURE, NULL,
			"L%u: Error allocating memory\n", line_number);
	}

	new_node->n = value;
	stack_push(*stack, new_node); // Use stack_push if needed
}

void pall(stack_t **stack) {
  if (!stack || !*stack) {
    return;
  }

  stack_t *node = *stack;
  while (node) {
    printf("%d\n", node->n);
    node = node->next;
  }
}

void stack_print(stack_t *node) {
  if (!node) {
    return;
  }
  stack_print(node->next);
  printf("%d\n", node->n);
}
