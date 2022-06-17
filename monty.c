#include "monty.h"

/**
 * monty - starts the monty interpreter
 */
void monty(void)
{
	char line[MAX_LEN];
	size_t line_len = MAX_LEN - 1;
	unsigned int line_number = 0;

	/* read line from input */
	while (fgets(line, line_len, op.input))
	{
		line_number++;
		exec_op(line, line_number);
	}

}

/**
 * exec_op - checks if a given string is a valid operation and executes it
 * @line: string
 * @line_number: line number of current instruction
 */
void exec_op(char *line, unsigned int line_number)
{
	void (*f)(stack_t **, unsigned int);
	char *message;

	get_op(line);

	if (op.opcode == NULL || op.opcode[0] == '#')
		return;

	f = get_op_func();
	if (f == NULL)
	{
		message = "L%u: unknown instruction %s\n";
		fprintf(stderr, message, line_number, op.opcode);
		free_op();
		exit(EXIT_FAILURE);
	}

	f(&(op.head), line_number);
}

/**
 * get_op - gets the correct operation from a given string and updates op
 * @line: string
 */
void get_op(char *line)
{
	char *str = line;

	while (*str)
	{
		if (*str < ' ')
			*str = ' ';

		str++;
	}

	if (op.opcode)
		free(op.opcode);

	if (op.arg)
		free(op.arg);

	op.opcode = _strdup(_strtok(line, " "));
	op.arg = _strdup(_strtok(NULL, " "));
}
