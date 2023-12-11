#include <stdlib.h>
#include "monty.h"

Stack *create_stack() {
  return NULL;
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

