#include "lists.h"

/**
 * free_dlistint - frees a list
 * @head: pointer to head node
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *curr, *new;

	curr = head;
	new = head;

	while (new)
	{
		new = new->next;
		free(curr);
		curr = new;
	}
}
