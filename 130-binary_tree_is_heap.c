#include "binary_trees.h"

int binary_tree_is_heap(const binary_tree_t *tree);
int check_head(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int tree_is_full(const binary_tree_t *tree, int i, int cnodes);
size_t binary_tree_cap(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_full(tree))
		return (0);

	return (check_head(tree->left) && check_head(tree->right));
}

/**
 * check_head - Checks if parent has a greater value than its childs.
 *
 * @tree: A pointer to the node.
 *
 * Return: 1 if parent has a greater value, 0 otherwise
 */

int check_head(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_head(tree->left) && check_head(tree->right));
}

/**
 * binary_tree_is_full - Calls to tree_is_complete function.
 *
 * @tree: Tree root.
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t c_nodes;

	if (tree == NULL)
		return (0);

	c_nodes = binary_tree_cap(tree);

	return (tree_is_full(tree, 0, c_nodes));
}

/**
 * tree_is_full - Checks if tree is complete.
 *
 * @tree: Pointer to the tree root.
 * @i: Node index.
 * @c_nodes: Number of nodes.
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int tree_is_full(const binary_tree_t *tree, int i, int c_nodes)
{
	if (tree == NULL)
		return (1);

	if (i >= c_nodes)
		return (0);

	return (tree_is_full(tree->left, (2 * i) + 1, c_nodes) &&
		tree_is_full(tree->right, (2 * i) + 2, c_nodes));
}


/**
 * binary_tree_cap - Measures the size of a binary tree.
 *
 * @tree: Tree root.
 * Return: Size of the tree or 0 if tree is NULL.
 */

size_t binary_tree_cap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_cap(tree->left) + binary_tree_cap(tree->right) + 1);
}
