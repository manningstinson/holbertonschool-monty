#include "monty.h"

void exit_error(int errcode, char *filename, const char *format, ...) {
  va_list args;
  va_start(args, format);

  switch (errcode) {
    case INVALID_BYTECODE:
      printf("Error: Unknown instruction %d\n", bytecode);
      break;
    case STACK_UNDERFLOW:
      printf("Error: Stack underflow\n");
      break;
    case INVALID_FILE:
      printf("Error: Could not open bytecode file '%s'\n", filename);
      break;
    /* Add cases for other error types */
  }

  if (format) {
    vprintf(format, args);
  }

  va_end(args);
  exit(errcode);
}
