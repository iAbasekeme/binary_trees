#include "binary_trees.h"
/**
 * binary_tree_leaves - A function that counts the leaves in a tree
 * @tree: The tree involved
 *
 * Return: size of all the leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree != NULL && tree->left == NULL && tree->right == NULL)
		return (1 + binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
	return (0);
}
