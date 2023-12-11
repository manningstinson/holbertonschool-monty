#include <stdlib.h>
#include "monty.h"

Stack *create_stack() {
  return NULL;
}

void push(Stack **top, int value) {
  if (!*top) {
    *top = malloc(sizeof(Stack));
    (*top)->n = value;
    (*top)->next = (*top)->prev = NULL;
  } else {
    Stack *new_node = malloc(sizeof(Stack));
    new_node->n = value;
    new_node->next = *top;
    (*top)->prev = new_node;
    *top = new_node;
  }
}

int pop(Stack **top) {
  if (!*top) {
    return -1;
  }

  int value = (*top)->n;
  Stack *temp = *top;
  *top = (*top)->next;
  if (*top) {
    (*top)->prev = NULL;
  }
  free(temp);
  return value;
}

void print_stack(Stack *top, int order) {
  if (!top) {
    return;
  }

  if (order == PALL_TOP_DOWN) {
    while (top) {
      printf("%d\n", top->n);
      top = top->next;
    }
  } else if (order == PALL_BOTTOM_UP) {
    stack_print(top);
  }
}

void stack_print(Stack *node) {
  if (!node) {
    return;
  }
  stack_print(node->next);
  printf("%d\n", node->n);
}

void free_stack(Stack **top) {
  while (*top) {
    Stack *tmp = *top;
    *top = (*top)->next;
    free(tmp);
  }
}
