#include "binary_trees.h"
/**
 * binary_tree_delete - A function that frees an entire binary tree
 * @tree: A pointer to the root of the tree to delete
 *
 * Return: No return
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}
