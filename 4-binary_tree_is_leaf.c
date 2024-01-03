#include "binary_trees.h"
/**
 * binary_tree_is_leaf - A function that checks if a node is a leaf
 * @node: Node to be checked
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL && node != NULL)
		return (1);
	else
		return (0);
}
