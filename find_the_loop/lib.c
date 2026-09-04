#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Adds a node at the beginning of a linked list
 * @head: Double pointer to the beginning of the list
 * @n: Integer to store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * print_listint_safe - Prints a linked list that may contain a loop
 * @head: Pointer to the first node
 *
 * Return: Number of different nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *loop;
	const listint_t *current;
	size_t count = 0;

	loop = find_listint_loop((listint_t *)head);
	current = head;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;

		if (current == loop)
		{
			printf("-> [%p] %d\n", (void *)loop, loop->n);
			break;
		}
	}

	return (count);
}

/**
 * free_listint_safe - Frees a linked list that may contain a loop
 * @h: Double pointer to the beginning of the list
 *
 * Return: Number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *loop;
	listint_t *current;
	listint_t *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	loop = find_listint_loop(*h);
	current = *h;

	while (current != NULL && current != loop)
	{
		next = current->next;
		free(current);
		current = next;
		count++;
	}

	if (loop != NULL)
	{
		current = loop->next;
		free(loop);
		count++;

		while (current != loop)
		{
			next = current->next;
			free(current);
			current = next;
			count++;
		}
	}
	else
	{
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
			count++;
		}
	}

	*h = NULL;
	return (count);
}
