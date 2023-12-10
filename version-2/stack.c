#include <stdlib.h>
#include "monty.h"

Stack *create_stack() {
  return NULL;
}

void push(Stack **top, int value) {
  Stack *new_node = malloc(sizeof(Stack));

  if (!new_node) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    exit(1);
  }

  new_node->value = value;
  new_node->next = *top;
  *top = new_node;
}

int pop(Stack **top) {
  if (*top == NULL) {
    return -1; // Error: Stack underflow
  }

  int value = (*top)->value;
  Stack *tmp = *top;
  *top = (*top)->next;
  free(tmp);

  return value;
}

void print_stack(Stack *top) {
  printf("[");
  while (top) {
    printf("%d ", top->value);
    top = top->next;
  }
  printf("]\n");
}

void free_stack(Stack **top) {
  while (*top) {
    Stack *tmp = *top;
    *top = (*top)->next;
    free(tmp);
  }
}

