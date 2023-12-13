#include"search_algos.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * binary_search - Search for an integer in a sorted array using binary search.
 * Return: The index of the first occurrence of @value, or -1 if not found.
 * */
int binary_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, mid;

	if (array == NULL || size < 1)
		return (-1);

	while (low <= high)
	{
		size_t i = low;

		mid = (low + high) / 2;
		printf("Searching in array: ");

		while (i <= high)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
			++i;
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	
	return (-1);
}
