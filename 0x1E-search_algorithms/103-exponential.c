#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search.
 *
 * Return: The first index where the value is located, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, bound);

	return (binary_search(array, bound / 2, (bound < size) ? bound : size, value));
}
