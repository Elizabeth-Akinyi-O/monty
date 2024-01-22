#include "monty'h"

/**
 * add_node_beg - adds a node at the beginning of a doubly linked list
 * @head: first position of the linked list
 * @n: data to be stored
 *
 * Return: a doubly linked list
 */
stack_t *add_node_beg(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glob_var;
		eixt(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * add_node_end - adds a node at the end of a linked list
 * @head: head of the linked list
 * @n: data to store
 *
 * Return: a doubly linked list
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *temp, *i;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}

	i = *head;
	while (i->next)
		i = i->next;
	temp->next = i->next;
	temp->prev = i;
	i->next = temp;
	return (i->next);
}

/**
 * free_nodes - frees the doubly linked list
 * @head: head of the list
 */
void free_nodes(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
