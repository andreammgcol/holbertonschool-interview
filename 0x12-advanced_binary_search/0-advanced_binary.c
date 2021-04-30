#include "search_algos.h"

/**
* b_search - basic binary search
* @array: array
* @first: first value array
* @last: last value array
* @value: value
* Return: the index of the value
*/
int b_search(int *array, int first, int last, int value)
{
	int mid = (first + last)  / 2, i;

	if (first > last)
		return (-1);
	printf("Searching in array: ");
	for (i = first; i <= last; i++)
	{
		if (i == last)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (array[mid] == value)
	{
		if (array[mid - 1] == value)
			return (b_search(array, first, mid, value));
		return (mid);
	}
	else if (array[mid] >= value)
		return (b_search(array, first, mid, value));
	else
		return (b_search(array, first + 1, last, value));
	return (-1);
}
/**
* advanced_binary - that searches for a value in a sorted array of integers
* @array: pointer to the first element of the array to search in
* @size: numbers of elements in array
* @value: value to search for
* Return: the index of the value
*/
int advanced_binary(int *array, size_t size, int value)
{
	int first = 0, last = (int)size - 1;

	if (array == NULL || size <= 0)
		return (-1);
	return (b_search(array, first, last, value));
}
