#include "list.h"


List *first_node(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(str);
		return (NULL);
	}
	new->next = new;
	new->prev = new;
	*list = new;
	return (new);
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *temp1, *temp2;

	if (list == NULL)
		return (NULL);
	if (*list == NULL)
		return (first_node(list, str));

	temp2 = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = temp2;
	new->prev = temp2->prev;
	temp1 = temp2->prev;
	temp2->prev = new;
	temp1->next = new;

	return (new);
}

/**
 * add_node_begin - Add a new node to the beginning
 * of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *temp1, *temp2;

	if (list == NULL)
		return (NULL);
	if (*list == NULL)
		return (first_node(list, str));

	temp2 = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = temp2;
	new->prev = temp2->prev;
	temp1 = temp2->prev;
	temp2->prev = new;
	temp1->next = new;
	*list = new;

	return (new);

}
