#include "binary_trees.h"
/**
 * binary_tree_is_root - A function that checks if a node is the parent or not.
 * @node: Node involved.
 *
 * Return: 1 if node is root, ottherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->parent == NULL)
		return (1);
	return (0);
}
