#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array using advanced binary search
 *
 * Return: Index of the first occurrence of value in the array, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

/**
 * advanced_binary_recursive - Recursive helper function for advanced binary search
 *
 * Return: Index of the first occurrence of value in the array, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	if (low > high)
		return (-1);

	size_t mid = (low + high) / 2;

	printf("Searching in array: ");
	print_array(array, low, high);

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		return (advanced_binary_recursive(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, high, value));
	else
		return (advanced_binary_recursive(array, low, mid - 1, value));
}

/**
 * print_array - Prints the elements of an array between the specified indices
 * @end: Ending index of the array to print
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i <= end; ++i)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
		else
			printf("\n");
	}
}
