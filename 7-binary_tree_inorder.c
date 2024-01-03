#include "binary_trees.h"
/**
 * binary_tree_inorder - traversal in-order function
 * @tree: a pointer to the root
 * @func: pointer function
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	/*traverse the left subtree*/
	binary_tree_inorder(tree->left, func);
	/*visit the root*/
	func(tree->n);
	/*visit the right subtree*/
	binary_tree_inorder(tree->right, func);
}
