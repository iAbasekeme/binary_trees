#include "binary_trees.h"
/**
 * binary_tree_nodes - A function that counts the with atleast
 * one child in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of nodes
 *
 * Return: Number of nodes with atleast 1 child in a binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count;

	if (!tree)
		return (0);

	count = (tree->left || tree->right) ? 1 : 0;

	count += binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);

	return (count);
}
