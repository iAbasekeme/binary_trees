#include "binary_trees.h"
/**
 * binary_tree_preorder - traversal pre-order function
 * @tree: pointer to the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/*visit the root*/
	func(tree->n);
	/*traverse the left subtree*/
	binary_tree_preorder(tree->left, func);
	/*traverse the right subtree*/
	binary_tree_preorder(tree->right, func);
}
