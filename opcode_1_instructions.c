#define _GNU_SOURCE
#include "monty.h"

/**
 * _push - This pushes an element to the stack.
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, i;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (i = 0; vglo.arg[i] != '\0'; i++)
	{
		if (!isdigit(vglo.arg[i]) && vglo.arg[i] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - This prints all values on the stack.
 *
 * @doubly: The head of the linked list.
 * @cline: The line numbers.
 * Return: Nothing to return.
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - This prints the value at the top of the stack.
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - This removes the top element of the stack.
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - This swaps the top two elements of the stack.
 *
 * @doubly: The head of the linked list.
 * @cline: The line number.
 * Return: Nothing to return.
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int n = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
