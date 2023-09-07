#include "hash_tables.h"
#include <stdio.h>

/**
 * key_index - Give index of a key.
 * @key: The key.
 * @size: size of the array.
 *
 * Return: index which key/value pair stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

	hash_value = hash_djb2(key);
	return (hash_value % size);
}


/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *prev;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev->key);
			free(prev->value);
			free(prev);
		}
	}

	free(ht->array);
	free(ht);
}
