#include "monty.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    /* Check for correct number of arguments */
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open and read the Monty bytecode file */
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Initialize stack and other variables if needed */

    /* Read and execute instructions from the file */
    if (!read_and_execute_instructions(file)) {
        fprintf(stderr, "Error: Execution failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    /* Close the file and free allocated memory if needed */
    fclose(file);

    return EXIT_SUCCESS;
}

