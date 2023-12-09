// monty.c

#include "monty.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Placeholder for your file parsing logic
    // Replace this with your actual implementation
    unsigned int line_number = 4;  // Simulating an error on line 4
    fprintf(stderr, "L%u: usage: push integer\n", line_number);

    fclose(file);
    return EXIT_SUCCESS;
}

