#include <stdlib.h>
#include <stdio.h>

#include "binary_trees.h"

/**
 * bt_preorder - transversal pre-order
 * @tree: pointer to root
 * @node: pointer to node
 * @h: height
 * @level: level of tree
 * Return:
 */
void bt_preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (tree == NULL)
		return;
	if (h == level)
		*node = tree;
	level++;
	if (tree->left)
		bt_preorder(tree->left, node, h, level);
	if (tree->right)
		bt_preorder(tree->right, node, h, level);
}

/**
* bt_height - calculate the height of a binary tree
* @tree: pointer to node
* Return: height
*/
size_t bt_height(const heap_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	if (tree->left)
		left_height = bt_height(tree->left);
	if (tree->right)
		right_height = bt_height(tree->right);

	if (left_height >= right_height)
		return (1 + left_height);
	return (1 + right_height);
}

/**
* heap_extract - that extracts the root node of a Max Binary Heap
* @root: double pointer to the root node of the heap
* Return: value stored in the root node or 0 if it fails
*/
int heap_extract(heap_t **root)
{
	int deleted, n;
	size_t level = 0;
	heap_t *aux, *del;

	if (root == NULL || *root == NULL)
		return (0);
	aux = *root, deleted = aux->n;
	if (aux->left == NULL && aux->right == NULL)
	{
		*root = NULL;
		free(aux);
		return (deleted);
	}
	bt_preorder(aux, &del, bt_height(aux), level);
	while (aux->left || aux->right)
	{
		if (aux->right == NULL || aux->left->n > aux->right->n)
		{
			n = aux->n, aux->n = aux->left->n;
			aux->left->n = n;
			aux = aux->left;
		}
		else if (aux->left == NULL || aux->right->n > aux->left->n)
		{
			n = aux->n, aux->n = aux->right->n;
			aux->right->n = n;
			aux = aux->right;
		}
	}
	aux->n = del->n;
	if (del->parent->right)
		del->parent->right = NULL;
	else
		del->parent->left = NULL;
	free(del);
	return (deleted);
}
