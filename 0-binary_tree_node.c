#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node.
 *
 * @parent: A pointer to the parent of the node.
 * @value: The value to be puted on the current node.
 *
 * Return: If it fails - NULL else - a pointer to the current node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *cur;

	cur = malloc(sizeof(binary_tree_t));
	if (cur == NULL)
		return (NULL);

	cur->n = value;
	cur->parent = parent;
	cur->left = NULL;
	cur->right = NULL;

	return (cur);
}
