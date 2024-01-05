#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root
 * Return: the height of the root
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hleft, hright;

	if (tree == NULL)
		return (-1);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/*Find recursively the height of left and right subtree*/
	hleft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	hright = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* return the longuest*/
	return (hleft > hright ? hleft : hright);
}

/**
 * binary_tree_balance - A function that calculates
 * the balance factor of a binary tree
 * @tree: A pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: Height of each tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left;
	int height_right;

	if (!tree)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return (height_left - height_right);
}
