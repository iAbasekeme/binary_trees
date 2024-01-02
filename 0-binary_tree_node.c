#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * binary_tree_node - A function that creates a binary tree node.
 * @parent: Pointer to the parent node of thr node to be created.
 * @value: The value to be put in the newnode
 *
 * Return: Pointer to the newly created node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *newNode;

    newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    if (!newNode)
        return NULL;

    newNode->parent = parent;
    newNode->n = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}