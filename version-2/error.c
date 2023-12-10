#include <stdio.h>

void error_invalid_bytecode(int bytecode) {
  printf("Error: Unknown instruction %d\n", bytecode);
}

void error_stack_underflow() {
  printf("Error: Stack underflow\n");
}

void error_invalid_file(char *filename) {
  printf("Error: Could not open bytecode file '%s'\n", filename);
}

// Add more error handling functions as needed

