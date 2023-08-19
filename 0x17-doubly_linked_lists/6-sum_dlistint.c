#include "lists.h"

/**
 * sum_dlistint - Computes the sum of all the data in list.
 * @head: Pointer to the head node.
 *
 * Return: sum or 0 for empty.
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temp;
	int sum = 0;

	if (head == NULL)
		return (0);

	temp = head;

	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
