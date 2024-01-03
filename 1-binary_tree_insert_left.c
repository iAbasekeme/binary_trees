#include "binary_trees.h"
/**
 * binary_tree_insert_left - A function that inserts
 * a node as the left-child of another node
 * @parent:  pointer to the node to insert the left-child in
 * @value:  value to store in the new node
 *
 * Return: Pointer to newNode, otherwise NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *newNode;
    if (!parent)
        return (NULL);

    newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    if (!newNode)
        return (NULL);

    newNode->parent = parent;
    newNode->n = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (parent->left)
    {
        newNode->left = parent->left;
        parent->left = newNode;
    }
    parent->left = newNode;

    return (newNode);
}
