#include "binary_trees.h"

/**
 * is_descendant - check if node is a descendant of a node
 * @ancestor: pointer to the ancestor node
 * @descendant: pointer to the descendant node
 * Return: 1 if true otherwise 0
 */
int is_descendant(const binary_tree_t *ancestor,
		const binary_tree_t *descendant)
{
	if (ancestor == NULL || descendant == NULL)
		return (0);

	while (descendant != NULL)
	{
		if (descendant->parent == ancestor)
			return (1);
		descendant = descendant->parent;
	}
	return (0);
}

/**
 * binary_trees_ancestor -finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *) first);

	ancestor = (binary_tree_t *) first;

	while (ancestor != NULL)
	{
		if (is_descendant(ancestor, second))
			return (ancestor);
		ancestor = ancestor->parent;
	}

	return (NULL);
}
