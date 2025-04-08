#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to head of list
 * @number: the number to insert
 * Return: address of new node, or NULL if failure
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new, *current;

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (!head || !(*head))  // Empty list
    {
        *head = new;
        return (new);
    }

    if (number < (*head)->n)  // Insert at the beginning
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    current = *head;

    while (current->next && current->next->n < number)
        current = current->next;

    new->next = current->next;
    current->next = new;

    return (new);
}