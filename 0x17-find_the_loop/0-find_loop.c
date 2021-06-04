#include "lists.h"

/**
 * detectLoop - check if there is a loop in linked list
 * @tmp_node: pointer
 * @h: pointer
 * Return: pointer loop start
 */

listint_t *detectLoop(listint_t *tmp_node, listint_t *h)
{
	while (tmp_node != h)
	{
		tmp_node = tmp_node->next;
		h = h->next;
	}
	return (tmp_node);
}

/**
 * find_listint_loop - that finds the loop in a linked list
 * @head: pointer
 * Return: nodes
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp_node, *h;

	if (head)
	{
		tmp_node = head->next;
		h = head->next->next;
		while (tmp_node && h)
		{
			if (tmp_node == h)
			{
				tmp_node = head;
				return (detectLoop(tmp_node, h));
			}
			tmp_node = tmp_node->next;
			h = h->next->next;
		}
	}
	return (0);
}
