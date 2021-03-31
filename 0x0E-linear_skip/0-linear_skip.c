#include "search.h"
/**
* linear_skip - searches for a value in a sorted skip list of integers
* @list: pointer to the head
* @value: value to search for
* Return: pointer on the first node where value is located
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp;
	size_t index1, index2;

	if (list == NULL)
		return (NULL);
	while (list->next && list->n < value)
	{
		if (list->express)
		{
			tmp = list;
			list = list->express;
			printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
			if (!list->express && value > list->n)
				tmp = list;
		}
		else
			list = list->next;
	}
	index1 = tmp->index, index2 = list->index;
	printf("Value found between indexes [%lu] and [%lu]\n", index1, index2);
	while (tmp->next && tmp->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
		tmp = tmp->next;
		if (!tmp->next)
			printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
	}
	if (tmp->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
		return (tmp);
	}
	return (NULL);
}
