#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer tho to root node of the BT
 * Return:  pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (tree == NULL || tree->right == NULL)
	{
		return (tree);  /*Cannot perform left rotation*/
	}

	x = tree;
	y = x->right;

	x->right = y->left;

	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;

	if (y->parent == NULL)
		tree = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;

	return (tree);
}
