#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle
 * @list: Pointer to the head of the list
 *
 * Return: 1 if cycle exists, 0 otherwise
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list;
    listint_t *fast = list;

    if (!list) // Vérifie si la liste est vide
        return (0);

    while (fast && fast->next) // Tant qu'on n'atteint pas NULL
    {
        slow = slow->next;       // Avance d'un nœud
        fast = fast->next->next; // Avance de deux nœuds

        if (slow == fast) // 🔥 Si les deux pointeurs se croisent, il y a un cycle !
            return (1);
    }

    return (0); // Si `fast` atteint NULL, il n'y a pas de cycle
}
