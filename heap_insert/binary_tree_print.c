#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* helper functions */
static int _height(const binary_tree_t *tree);
static void _print(const binary_tree_t *tree, int offset, int depth, char **s);
static int _max(int a, int b);
static char *_itoa(int n);

void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    int height, i;

    if (!tree)
        return;

    height = _height(tree);
    s = malloc(sizeof(*s) * height * 10);
    if (!s)
        return;
    for (i = 0; i < height * 10; i++)
    {
        s[i] = malloc(255);
        if (!s[i])
            return;
        memset(s[i], 32, 254);
        s[i][254] = '\0';
    }

    _print(tree, 0, 0, s);

    for (i = 0; i < height * 10 && s[i][0] != '\0'; i++)
    {
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}

static void _print(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char *b;
    int width;

    if (!tree)
        return;

    b = _itoa(tree->n);
    width = strlen(b);

    memcpy(&s[depth][offset], b, width);

    free(b);

    if (tree->left)
        _print(tree->left, offset - 4, depth + 2, s);
    if (tree->right)
        _print(tree->right, offset + 4, depth + 2, s);
}

static int _height(const binary_tree_t *tree)
{
    int left, right;

    if (!tree)
        return (0);
    left = _height(tree->left);
    right = _height(tree->right);
    return (1 + _max(left, right));
}

static int _max(int a, int b)
{
    return (a >= b ? a : b);
}

static char *_itoa(int n)
{
    char *str;
    int len = snprintf(NULL, 0, "%03d", n);
    str = malloc(len + 1);
    if (str)
        snprintf(str, len + 1, "%03d", n);
    return str;
}

