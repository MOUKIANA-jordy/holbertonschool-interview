#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - Singly linked list node
 * @n: Integer stored in the node
 * @next: Pointer to the next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *find_listint_loop(listint_t *head);

#endif /* LISTS_H */
