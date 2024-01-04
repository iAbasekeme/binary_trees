#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: the sibling of a node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left != NULL && node->parent->left != node)
		return (node->parent->left);
	else if (node->parent->right != NULL && node->parent->right != node)
		return (node->parent->right);

	return (NULL);
}
