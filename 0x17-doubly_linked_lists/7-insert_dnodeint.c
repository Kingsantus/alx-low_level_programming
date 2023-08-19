#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a index position
 * @h: Pointer to the head
 * @idx: Index to assign the new node
 * @n: Value of data
 *
 * Return: data or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int count = 0;

	if (*h == NULL && idx != 0)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*h == NULL && idx == 0)
	{
		*h = new_node;
		return (new_node);
	}

	if (idx == 0)
	{
		new_node->next = *h;
		(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	temp = *h;

	while (count < idx - 1)
	{
		count++;
		temp = temp->next;
		if (temp == NULL)
			return (NULL);
	}

	if (temp->next)
		temp->next->prev = new_node;

	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next = new_node;

	return (new_node);
}
