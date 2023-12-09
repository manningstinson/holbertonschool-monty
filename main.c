#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (!read_and_execute_instructions(file)) {
        fprintf(stderr, "Error: Execution failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
