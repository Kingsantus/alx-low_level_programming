#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given position
 * @head: Pointer to a node
 * @index: Index to be deleted
 *
 * Return: 1 successful, -1 empty
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int count = 0;

	if (!*head)
		return (-1);

	temp = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}
	while (count < index)
	{
		count++;
		temp = temp->next;

		if (!temp)
			return (-1);
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	return (1);
}
