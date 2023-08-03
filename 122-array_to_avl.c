#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
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
			if (avl_insert(&tree, array[mark]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
