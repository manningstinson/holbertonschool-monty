#include "monty.h"
#include <stdlib.h>  /* For EXIT_FAILURE and EXIT_SUCCESS */
#include <stdio.h>   /* For fprintf */

/**
 * cleanup_wrapper - Wrapper function for atexit with the correct signature
 */
void cleanup_wrapper(void)
{
	cleanup(NULL);
}

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	char *filename = argv[1];

	stack_t *stack = NULL;

	if (read_file(filename, &stack) == EXIT_FAILURE)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		cleanup(stack);
		return (EXIT_FAILURE);
	}
	atexit(cleanup_wrapper);
	cleanup(stack);

	return (EXIT_SUCCESS);
}
