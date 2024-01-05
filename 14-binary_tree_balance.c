#include "binary_trees.h"
/**
 * binary_tree_balance - A function that calculates the balance factor of a binary tree
 * @tree: A pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: Height of each tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	int height_left;
	int height_right;

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return height_left - height_right;
}
