#include "binary_trees.h"


/**
* binary_tree_node - creates a binary tree node
* @parent: parent node
* @value: value for the new node
* Return: the new node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->n = value;
	new->parent = parent;
	return (new);
}

/**
* to_help - builds an AVL tree from an array
* @array: pointer to array
* @start: start of array
* @end: end of array
* @parent: pointer parent
* Return: pointer to the new avl
*/
avl_t *to_help(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *root;
	size_t mid;

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	if (start > end)
		return (NULL);

	if (mid != start)
		root->left = to_help(array, start, mid - 1, root);

	if (mid != end)
		root->right = to_help(array, mid + 1, end, root);
	return (root);
}

/**
* sorted_array_to_avl - builds an AVL tree from an array
* @array: pointer to array
* @size: size of array
* Return: pointer to the new avl
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (array == NULL || size == 0)
		return (NULL);

	root = to_help(array, 0, size - 1, NULL);

	return (root);
}
