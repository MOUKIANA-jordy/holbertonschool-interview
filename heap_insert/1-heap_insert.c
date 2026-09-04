#include <stddef.h>
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
 * find_parent - Finds the parent of a node using its index
 * @root: Pointer to the root node
 * @index: Level-order index of the parent
 *
 * Return: Pointer to the parent node
 */
static heap_t *find_parent(heap_t *root, size_t index)
{
	size_t bit;

	bit = 1;

	while (bit <= index / 2)
		bit <<= 1;

	bit >>= 1;

	while (bit > 0)
	{
		if (index & bit)
			root = root->right;
		else
			root = root->left;

		bit >>= 1;
	}

	return (root);
}

/**
 * move_up - Restores the Max Heap ordering
 * @node: Pointer to the inserted node
 *
 * Return: Pointer to the node containing the inserted value
 */
static heap_t *move_up(heap_t *node)
{
	int temporary;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		temporary = node->n;
		node->n = node->parent->n;
		node->parent->n = temporary;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the node containing the inserted value
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	heap_t *new;
	size_t index;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	index = heap_size(*root) + 1;
	parent = find_parent(*root, index / 2);
	new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	if (index % 2 == 0)
		parent->left = new;
	else
		parent->right = new;

	return (move_up(new));
}
