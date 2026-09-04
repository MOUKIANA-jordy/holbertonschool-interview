#include <stdlib.h>
#include "list.h"

/**
 * copy_string - Copies a string
 * @str: String to copy
 *
 * Return: Pointer to the copy, or NULL on failure
 */
static char *copy_string(char *str)
{
	char *copy;
	int length = 0;
	int index;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	copy = malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (NULL);

	for (index = 0; index <= length; index++)
		copy[index] = str[index];

	return (copy);
}

/**
 * create_node - Creates a new list node
 * @str: String to store in the node
 *
 * Return: Address of the new node, or NULL on failure
 */
static List *create_node(char *str)
{
	List *new;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = copy_string(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->prev = NULL;
	new->next = NULL;

	return (new);
}

/**
 * add_node_end - Adds a node to the end of the list
 * @list: Double pointer to the beginning of the list
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new = create_node(str);
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;
	new->prev = last;
	new->next = *list;
	last->next = new;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - Adds a node to the beginning of the list
 * @list: Double pointer to the beginning of the list
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;
	List *last;

	if (list == NULL || str == NULL)
		return (NULL);

	new = create_node(str);
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->next = new;
		new->prev = new;
		*list = new;
		return (new);
	}

	last = (*list)->prev;
	new->next = *list;
	new->prev = last;
	last->next = new;
	(*list)->prev = new;
	*list = new;

	return (new);
}
