#include "lists.h"
#include <stdio.h>

/**
* *insert_node - function that inserts a number into a sorted linked list
* @head: pointer
* @number: node to be inserted
* Return: the address of the new node, or NULL if it failed
**/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t  *new;
	listint_t  *current;

	if (head == NULL)
	{
		return (NULL);
	}

	new = malloc(sizeof(listint_t));

        if (new == NULL)
        {
        	return (NULL);
        }
	new->n = number;


	if (*head == NULL || (*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
	}
	
	else
	{
		current = *head;

		while (current->next != NULL && current->next->n < new->n)
    {
			current = current->next;
		}

		new->next = current->next;
		current->next = new;
	}
	return (new);
}
