#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to count the number of leaves.
 *
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves = leaves + (!tree->left && !tree->right) ? 1 : 0;
		leaves = leaves + binary_tree_leaves(tree->left);
		leaves = leaves + binary_tree_leaves(tree->right);
	}

	return (leaves);
}
