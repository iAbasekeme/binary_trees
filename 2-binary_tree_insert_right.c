#include "binary_trees.h"
/**
 * binary_tree_insert_right - A fucntion that inserts a node at
 * the right node of another node
 * @parent: A pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: A pointer to the newly inserted Node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);
	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent->right)
	{
		newNode->right = parent->right;
		parent->right->parent = newNode;
	}
	parent->right = newNode;

	return (newNode);
}
