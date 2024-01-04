#include "binary_trees.h"
/**
 * binary_tree_is_full -  checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if a full BT otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NUL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
