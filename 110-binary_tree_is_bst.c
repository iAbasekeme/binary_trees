#include "binary_trees.h"
/**
 * storeArray - function that store BT into array
 * @root: pointer to the root of the BT
 * @array: pointer the array
 * @index: index
 */
void storeArray(binary_tree_t *root, int array[], int *index)
{
	if (root != NULL)
	{
		storeArray(root->left, array, index);
		array[(*index)++] = root->n;

		storeArray(root->right, array, index);
	}
}
/**
 * binary_tree_size -  A function that measures the size of a binery tree
 * @tree: The considered tree
 *
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
 * BinaryToArray -form an array  from a BT
 * @root: pointer to the root of the BT
 * Return: the formed array
 */
int *BinaryToArray(binary_tree_t  *root)
{
	size_t treesize = binary_tree_size(root);
	int *array = malloc(sizeof(int) * treesize);
	int index = 0;

	storeArray(root, array, &index);

	return (array);
}
/**
 * binary_tree_is_bst - check if BT is BST
 * @tree: pointer to the root of the BT
 * Return: 1 if true otherwise 0
 */
int  binary_tree_is_bst(const binary_tree_t *tree)
{
	int *array;
	size_t size;
	size_t i;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	array = BinaryToArray((binary_tree_t *)tree);
	for (i = 1; i < size; i++)
	{
		{
			if (array[i] <= array[i - 1])
				return (0);
		}
	}
	return (1);
}
