#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *latest, *cur;

	if (tree != NULL)
	{
		latest = *tree;
		if (latest == NULL)
		{
			cur = binary_tree_node(latest, value);
			if (cur == NULL)
				return (NULL);
			return (*tree = cur);
		}
		if (value < latest->n)
		{
			if (latest->left != NULL)
				return (bst_insert(&latest->left, value));
			cur = binary_tree_node(latest, value);
			if (cur == NULL)
				return (NULL);
			return (latest->left = cur);
		}
		if (value > latest->n)
		{
			if (latest->right != NULL)
				return (bst_insert(&latest->right, value));
			cur = binary_tree_node(latest, value);
			if (cur == NULL)
				return (NULL);
			return (latest->right = cur);
		}
	}

	return (NULL);
}
