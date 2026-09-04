#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_size - Counts the number of nodes in a heap
 * @root: Pointer to the root node
 *
 * Return: Number of nodes in the heap
 */
static size_t heap_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * get_last_node - Finds a node using its level-order index
 * @root: Pointer to the root node
 * @index: One-based index of the node
 *
 * Return: Pointer to the requested node
 */
static heap_t *get_last_node(heap_t *root, size_t index)
{
	size_t mask;

	if (root == NULL || index == 0)
		return (NULL);

	for (mask = 1; mask <= index; mask <<= 1)
		;

	mask >>= 2;

	while (mask > 0 && root != NULL)
	{
		if (index & mask)
			root = root->right;
		else
			root = root->left;

		mask >>= 1;
	}

	return (root);
}

/**
 * heapify_down - Restores the Max Binary Heap property
 * @root: Pointer to the root node
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;
	int temporary;

	while (root != NULL)
	{
		largest = root;

		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;

		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temporary = root->n;
		root->n = largest->n;
		largest->n = temporary;
		root = largest;
	}
}

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Double pointer to the root node
 *
 * Return: Value stored in the root, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	size_t size;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	size = heap_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root, size);
	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
