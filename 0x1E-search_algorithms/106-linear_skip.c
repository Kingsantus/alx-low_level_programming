#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * create_skiplist - Creates a skip list from an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: A pointer to the head of the skip list.
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
    skiplist_t *head = NULL;
    skiplist_t *current = NULL;
    skiplist_t *express = NULL;

    if (array == NULL || size == 0)
        return NULL;


    for (size_t i = 0; i < size; ++i)
    {
        skiplist_t *new_node = malloc(sizeof(skiplist_t));
        if (new_node == NULL)
        {
            perror("Failed to allocate memory for skip list node");
            exit(EXIT_FAILURE);
        }

        new_node->n = array[i];
        new_node->index = i;
        new_node->next = NULL;
        new_node->express = NULL;

        if (head == NULL)
            head = new_node;

        if (current != NULL)
            current->next = new_node;

        current = new_node;

        if (i == 0 || i % (size_t)sqrt(size) == 0)
        {
            if (express != NULL)
                express->express = new_node;

            express = new_node;
        }
    }

    return head;
}

/**
 * print_skiplist - Prints the elements of the skip list and its express lane.
 * @list: A pointer to the head of the skip list.
 */
void print_skiplist(const skiplist_t *list)
{
    const skiplist_t *current = list;
    const skiplist_t *express = list;

    printf("List :\n");
    while (current != NULL)
    {
        printf("Index[%lu] = [%d]\n", current->index, current->n);
        current = current->next;
    }

    printf("\nExpress lane :\n");
    while (express != NULL)
    {
        printf("Index[%lu] = [%d]\n", express->index, express->n);
        express = express->express;
    }

    printf("\n");
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (list == NULL)
        return NULL;

    skiplist_t *current = list;
    skiplist_t *express = list;

    while (express != NULL && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        current = express;
        express = express->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", current->index, express->index);

    while (current != NULL && current->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

        if (current->n == value)
            return current;

        current = current->next;
    }

    return NULL;
}

/**
 * free_skiplist - Frees the memory allocated for the skip list.
 * @list: A pointer to the head of the skip list.
 */
void free_skiplist(skiplist_t *list)
{
    skiplist_t *current = list;
    skiplist_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

