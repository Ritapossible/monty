#include "monty.h"

/**
 *add_dnodeint_end - This adds a note at the end of the doubly link list.
 *@head: The first position of linked list.
 *@m: The data to store.
 *Return: A doubly linked list.
 */
stack_t *add_dnodeint_end(stack_t **head, const int m)
{
	stack_t *tmp, *aux;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->m = m;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	tmp->next = aux->next;
	tmp->prev = aux;
	aux->next = tmp;
	return (aux->next);
}

/**
 *add_dnodeint - This adds a note at the begining of the doubly link list.
 *@head: The first position of linked list.
 *@m: The data to store.
 *Return: A doubly linked list.
 */
stack_t *add_dnodeint(stack_t **head, const int m)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->m = m;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlistint - This frees the doubly linked list
 *
 * @head: The head of the list
 * Return: Always no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
