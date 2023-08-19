#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be stored in the new node.
 *
 * Return: Pointer to the updated head of the list.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		dlistint_t *temp = *head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}

	return (*head);
}
