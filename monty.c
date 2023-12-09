#include "monty.h"  // Include your header file

int main(int argc, char *argv[]) {
    /* Check for the correct number of command-line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open the file for reading */
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read each line from the file */
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;

    while ((read = getline(&line, &len, file)) != -1) {
        /* Remove the newline character if present */
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
            read--;
        }

        /* Process the line (use your existing code for this part) */
        /* ... */
    }

    /* Clean up resources */
    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}

