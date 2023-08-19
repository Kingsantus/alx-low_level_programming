#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be stored in the new node.
 *
 * Return: Pointer to the newly added node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;

	return (*head);
}
