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
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/*Find recursively the height of left and right subtree*/
	hleft = binary_tree_height(tree->left);
	hright = binary_tree_height(tree->right);

	/* return the longuest*/
	return (1 + (hleft > hright ? hleft : hright));
}
