#include "lists.h"

/**
 * print_dlistint - Prints the elements of a doubly linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of elements printed.
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t count = 0;

	if (!h)
		return (count);

	while (!temp)
	{
		printf("%d\n", temp->n);
		count++;
		temp = temp->next;
	}

	return (count);
}
