#include "monty.h"
#include <stdio.h>

op_t op = {NULL, NULL, NULL, NULL};

/**
 * main - starts the Monty interpreter program
 * @argc: number of commandline arguments
 * @argv: array of commandline arguments
 *
 * Return: EXIT_SUCCESS on success. EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	/* check usage */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open given file */
	op.input = fopen(argv[1], "r");
	if (op.input == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty();

	free_op();
	return (EXIT_SUCCESS);
}
