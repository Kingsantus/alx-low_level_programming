#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates sorted hash table
 * @size: size of the table
 *
 * Return: points to the hash table, or NULL
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Inserts or updates a key/value
 * @ht: hash table
 * @key: key string
 * @value: value to the key
*
* Return: 1 on success, 0 on failure
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp, *prev;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
	}
	else if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		tmp = ht->shead;
		while (tmp != NULL && strcmp(new_node->key, tmp->key) > 0)
		{
			prev = tmp;
			tmp = tmp->snext;
		}
		new_node->sprev = prev;
		new_node->snext = tmp;
		prev->snext = new_node;
		if (tmp != NULL)
			tmp->sprev = new_node;
		else
			ht->stail = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key
 * @ht: hash table
 * @key: string key
 *
 * Return: associated value, or NULL
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the key/value pairs
 * @ht: hash table
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int flag = 0;
	unsigned long int i;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			flag = 1;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the key/value pairs in reverse order
 * @ht: hash table
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (ht == NULL)
		return;

	tmp = ht->stail;
	printf("{");
	while (tmp != NULL)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		if (tmp->sprev != NULL)
			printf(", ");
		tmp = tmp->sprev;
	}
	printf("}\n");
}
