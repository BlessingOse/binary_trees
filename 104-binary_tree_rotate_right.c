#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *whirl, *_tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	whirl = tree->left;
	_tmp = whirl->right;
	whirl->right = tree;
	tree->left = _tmp;
	if (_tmp != NULL)
		_tmp->parent = tree;
	_tmp = tree->parent;
	tree->parent = whirl;
	whirl->parent = _tmp;
	if (_tmp != NULL)
	{
		if (_tmp->left == tree)
			_tmp->left = whirl;
		else
			_tmp->right = whirl;
	}

	return (whirl);
}
