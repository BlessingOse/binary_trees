#include "binary_trees.h"

avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_insert_cir(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
int lev(const binary_tree_t *tree);
size_t peak(const binary_tree_t *tree);

/**
 * avl_insert - Inserts a value in an AVL Tree.
 *
 * @tree: A double pointer to the root node of the AVL tree for inserting.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_cir(tree, *tree, &new, value);
	return (new);
}

/**
 * avl_insert_cir - Inserts a value into an AVL tree recursively.
 *
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */

avl_t *avl_insert_cir(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int b_factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_cir(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_cir(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	b_factor = lev(*tree);
	if (b_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * lev - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */

int lev(const binary_tree_t *tree)
{
	return (tree != NULL ? peak(tree->left) - peak(tree->right) : 0);
}

/**
 * peak - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t peak(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t sideA = 0, sideB = 0;

		sideA = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		sideB = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((sideA > sideB) ? sideA : sideB);
	}
	return (0);
}
