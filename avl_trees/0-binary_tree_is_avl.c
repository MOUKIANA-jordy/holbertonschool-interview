#include <limits.h>
#include "binary_trees.h"

/**
 * check_avl - Checks the BST and balance properties of a tree
 * @tree: Pointer to the root of the current subtree
 * @minimum: Minimum value allowed
 * @maximum: Maximum value allowed
 * @height: Pointer used to store the subtree height
 *
 * Return: 1 if the subtree is a valid AVL tree, otherwise 0
 */
static int check_avl(const binary_tree_t *tree, long minimum,
		     long maximum, int *height)
{
	int left_height;
	int right_height;
	int difference;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (tree->n <= minimum || tree->n >= maximum)
		return (0);

	if (!check_avl(tree->left, minimum, tree->n, &left_height))
		return (0);

	if (!check_avl(tree->right, tree->n, maximum, &right_height))
		return (0);

	difference = left_height - right_height;

	if (difference < -1 || difference > 1)
		return (0);

	if (left_height > right_height)
		*height = left_height + 1;
	else
		*height = right_height + 1;

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	return (check_avl(tree, LONG_MIN, LONG_MAX, &height));
}
