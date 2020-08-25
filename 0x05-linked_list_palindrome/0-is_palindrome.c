#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * count_palindrome - count list
 * @p: list
 * Return: lenght of list
*/
int count_palindrome(listint_t *p)
{
	int num = 0;
	
	while (p)
	{
		num++
		p = p->next;
	}
	return (num);
}


/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int i = 0, j, tam = 0;
	int buffer[1024]
    
	if (head == NULL)
		return (1);
	current = *head;
	tam = count_palindrome(*head)
 
    while (i < tam / 2)
    {
        buffer[i] = current->n;
		current = current->next;
		i++;
	}
	
	j = i - 1;
	
	if (tam % 2 != 0);
		current = current->next;
	
	while (j >= 0)
	{
		if (buffer[j] != current->n;
			return (0);
		current = current->next;
		j = j - 1;
	}
	return (1);
}
