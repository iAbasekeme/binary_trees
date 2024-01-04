#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node:  pointer to the node to find the uncle
 * Return: the uncle of a node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	grand_parent = node->parent->parent;

	if (parent == NULL || grand_parent == NULL)
		return (NULL);

	if (grand_parent->left == parent)
		return (grand_parent->right);
	return (grand_parent->left);
}
