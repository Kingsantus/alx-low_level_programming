#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node at a given index.
 * @head: Pointer to the head node of the list.
 * @index: input index.
 *
 * Return: Pointer at agiven index, or NULL if the list is empty.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	temp = head;

	while (temp != NULL)
	{
		if (count == index)
			return (temp);
		count++;
		temp = temp->next;
	}
	return (NULL);
}
