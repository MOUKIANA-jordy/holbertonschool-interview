#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Fusionne deux sous-tableaux triés
 * @array: pointeur vers le tableau original
 * @left: indice de début du sous-tableau gauche
 * @mid: indice de fin du sous-tableau gauche
 * @right: indice de fin du sous-tableau droit
 * @buffer: tampon temporaire pour la fusion
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *buffer)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}
	while (i <= mid)
		buffer[k++] = array[i++];
	while (j <= right)
		buffer[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_rec - Fonction récursive de tri fusion
 * @array: pointeur vers le tableau original
 * @left: indice gauche
 * @right: indice droit
 * @buffer: tampon temporaire
 */
void merge_sort_rec(int *array, size_t left, size_t right, int *buffer)
{
	size_t mid;

	if (left >= right)
		return;

	/* Correction : sous-tableau gauche ≤ sous-tableau droit */
	mid = left + (right - left - 1) / 2;

	merge_sort_rec(array, left, mid, buffer);
	merge_sort_rec(array, mid + 1, right, buffer);

	merge(array, left, mid, right, buffer);
}

/**
 * merge_sort - Trie un tableau d’entiers avec l’algorithme Merge Sort
 * @array: pointeur vers le tableau
 * @size: taille du tableau
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_sort_rec(array, 0, size - 1, buffer);
	free(buffer);
}
