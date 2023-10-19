#include "monty.h"

/**
 * _rotl - Rotates the first element to the bottom and  the second to the top.
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *auxx = NULL;
	stack_t *auxy = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	auxx = (*doubly)->next;
	auxy = *doubly;

	for (; auxy->next != NULL; auxy = auxy->next)
		;

	auxx->prev = NULL;
	auxy->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = auxy;
	*doubly = auxx;
}

/**
 * _rotr - This reverses the stack.
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux = *doubly;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}
