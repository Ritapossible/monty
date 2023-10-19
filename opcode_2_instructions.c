#include "monty.h"

/**
 * _queue - This sets the format of the data to a queue (FIFO).
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - This sets the format fo the data to a stack (LIFO).
 *
 * @doubly:The  head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * _add - This adds the top two elements of the stack.
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - This doesn't do anythinhg.
 *
 * @doubly: The head of the linked list.
 * @cline:The line number.
 * Return: No to return.
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - This subtracts the top element to the second top element of stack.
 *
 * @doubly:The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
