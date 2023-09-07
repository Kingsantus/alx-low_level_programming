#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_create - Creates a hash table
 * @size: size of the array
 *
 * Return: A pointer to created hash table or NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	hash_node_t **array;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	array = malloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		array[i] = NULL;

	ht->size = size;
	ht->array = array;

	return (ht);
}
