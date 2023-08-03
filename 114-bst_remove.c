#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_remove_cir(bst_t *root, bst_t *node, int value);
bst_t *bst_DEL(bst_t *root, bst_t *node);
bst_t *inorder_nxt(bst_t *root);

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 *
 * @root: A pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removing.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_cir(root, root, value));
}

/**
 * bst_remove_cir - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */

bst_t *bst_remove_cir(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_DEL(root, node));
		if (node->n > value)
			return (bst_remove_cir(root, node->left, value));
		return (bst_remove_cir(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_DEL - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */

bst_t *bst_DEL(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *nxt = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	nxt = inorder_nxt(node->right);
	node->n = nxt->n;

	return (bst_DEL(root, nxt));
}

/**
 * inorder_nxt - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */

bst_t *inorder_nxt(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
