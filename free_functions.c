#include "monty.h"

/**
 * free_list - frees a doubly linked list
 * @head: pointer to the first element in the list
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * free_op - frees the op structure
 */
void free_op(void)
{
	if (op.opcode)
		free(op.opcode);

	if (op.arg)
		free(op.arg);

	free_list(op.head);
	fclose(op.input);
}
