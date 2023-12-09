#include "monty.h"
#include <stdio.h>

/* Add more error-handling functions as needed */

void handle_malloc_error(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

