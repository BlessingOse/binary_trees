#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t mark, MARK;

	if (array == NULL)
		return (NULL);

	for (mark = 0; mark < size; mark++)
	{
		for (MARK = 0; MARK < mark; MARK++)
		{
			if (array[MARK] == array[mark])
				break;
		}
		if (MARK == mark)
		{
			if (bst_insert(&tree, array[mark]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
