#include "binary_trees.h"
/**
 * binary_tree_nodes - A fucntion that counts the number of nodes
 * with atleast one child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Number of nodes with atleast one child in them
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	size_t count;

	count = (tree->left != NULL || tree->right != NULL) ? 1 : 0;
	count += binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
	return (count);
}
