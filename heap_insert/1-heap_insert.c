#include "binary_trees.h"
#include <stdlib.h>

/* === Prototypes === */
size_t binary_tree_size(const binary_tree_t *tree);
heap_t *get_parent_for_insert(heap_t *root, size_t path);
void heapify_up(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size_t size = binary_tree_size(*root);
	size_t path = size + 1;
	heap_t *parent = get_parent_for_insert(*root, path);
	heap_t *new = binary_tree_node(parent, value);

	if (!new)
		return (NULL);

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	heapify_up(new);

	return (new);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_parent_for_insert - Gets the parent node where to insert next
 * @root: Root of the heap
 * @path: Index to follow (like a binary heap array)
 *
 * Return: Pointer to parent node
 */
heap_t *get_parent_for_insert(heap_t *root, size_t path)
{
	heap_t *node = root;
	size_t bits[64], count = 0;

	/* Convert path index to binary (skipping first bit) */
	while (path > 1)
	{
		bits[count++] = path % 2;
		path /= 2;
	}

	for (int i = count - 1; i > 0; i--)
		node = bits[i] ? node->right : node->left;

	return (node);
}

/**
 * heapify_up - Swaps node with parent until heap property is restored
 * @node: Newly inserted node
 */
void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

