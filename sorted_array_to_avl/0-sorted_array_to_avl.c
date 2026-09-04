#include <stdlib.h>
#include "binary_trees.h"

/**
 * delete_tree - Frees an entire binary tree
 * @tree: Pointer to the root of the tree
 */
static void delete_tree(avl_t *tree)
{
	if (tree == NULL)
		return;

	delete_tree(tree->left);
	delete_tree(tree->right);
	free(tree);
}

/**
 * build_avl - Builds an AVL tree from part of a sorted array
 * @array: Sorted array of integers
 * @start: Starting index of the current part
 * @end: Ending index, excluded from the current part
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root of the created subtree
 */
static avl_t *build_avl(int *array, size_t start, size_t end,
			avl_t *parent)
{
	avl_t *node;
	size_t middle;

	if (start >= end)
		return (NULL);

	middle = start + (end - start) / 2;
	node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);

	node->n = array[middle];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	node->left = build_avl(array, start, middle, node);
	if (middle > start && node->left == NULL)
	{
		delete_tree(node);
		return (NULL);
	}

	node->right = build_avl(array, middle + 1, end, node);
	if (middle + 1 < end && node->right == NULL)
	{
		delete_tree(node);
		return (NULL);
	}

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, size, NULL));
}
