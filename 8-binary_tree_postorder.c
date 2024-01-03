#include "binary_trees.h"
/**
 * binary_tree_postorder - traversal post-order function
 * @tree: a pointer to the root
 * @func: pointer function
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	/*traverse the left subtree*/
	binary_tree_postorder(tree->left, func);
	/*visit the right subtree*/
	binary_tree_postorder(tree->right, func);
	/*visit the root*/
	func(tree->n);
}
