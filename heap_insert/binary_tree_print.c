#include <stdio.h>
#include "binary_trees.h"

/**
 * print_tree - Prints a binary tree recursively
 * @tree: Pointer to the current node
 * @depth: Depth of the current node
 */
static void print_tree(const binary_tree_t *tree, int depth)
{
	int index;

	if (tree == NULL)
		return;

	print_tree(tree->right, depth + 1);

	for (index = 0; index < depth; index++)
		printf("    ");

	printf("%d\n", tree->n);

	print_tree(tree->left, depth + 1);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	print_tree(tree, 0);
}
