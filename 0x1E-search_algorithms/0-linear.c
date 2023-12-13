#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Linear search in an array. 
 * Returns the index of the first occurrence of the value, or -1 if not found or if the array is NULL.
 * */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (array == NULL)
		return (-1);

	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		++i;
	}

	return (-1);
}
