#include "monty.h"

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the Monty instruction file for reading
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        // Print an error message if the file cannot be opened
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Rest of your main function
    // ...

    return EXIT_SUCCESS;
}

