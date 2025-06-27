#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - Creates a new AVL node
 * @parent: Parent node
 * @value: Value of the node
 * Return: Pointer to new node
 */
avl_t *create_node(avl_t *parent, int value)
{
    avl_t *node = malloc(sizeof(avl_t));

    if (!node)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/**
 * build_avl - Recursively builds AVL tree from sorted array
 * @array: Input array
 * @start: Starting index
 * @end: Ending index
 * @parent: Parent node
 * Return: Pointer to root of subtree
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
    avl_t *root;
    int mid;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;
    root = create_node(parent, array[mid]);
    if (!root)
        return (NULL);

    root->left = build_avl(array, start, mid - 1, root);
    root->right = build_avl(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree
 * @array: Pointer to array
 * @size: Size of array
 * Return: Pointer to root of AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl(array, 0, (int)size - 1, NULL));
}

