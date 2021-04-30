#include "search_algos.h"

/**
*print_array - print array
*@array: pointer
*@first: first element in array
*@last: last element in array
**/

void print_array(int *array, int first, int last)
{
	int i;

	printf("Searching in array: ");

	for (i = first; i <= last; i++)
	{
		printf("%d", array[i]);

		if (i != last)
		{
			printf(", ");
		}
	}
	printf("\n");
}

/**
*search_recursion - that searches a value in a sorted array of int
*@array: pointer
*@first: first element in array
*@last: last element in array
*@value: index of array
* Return: index where value is located or -1
**/

int search_recursion(int *array, int first, int last, int value)
{
	int mid;

	print_array(array, first, last);

	if (first == last)
	{
		return (-1);
	}

	if (first <= last)
	{
		mid = first + (last - first) / 2;

		if (array[mid] == value && array[mid - 1] != value)
		{
			return (mid);
		}

		if (array[mid] >= value)
		{
			return (search_recursion(array, first, mid, value));
		}

		if (array[mid] <= value)
		{
			return (search_recursion(array, mid + 1, last, value));
		}
	}
	return (-1);
}


/**
*advanced_binary - function that searches for a value in a sorted array.
*@array: pointer to the first element of the array to search in
*@size: number of elements in array
*@value:  value to search for
* Return: index where value is located or -1
**/

int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (search_recursion(array, 0, size - 1, value));
}
