#include "sort.h"


/**
 * h_array - turns the array into a heap
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing
 */
void h_array(int *array, size_t size)
{
	ssize_t start = 0;

	start = (size - 2) / 2;
	while (start >= 0)
	{
		siftdown(array, (size_t)start, size - 1, size);
		if (start)
			start--;
		else
			break;
	}
}

/**
 * siftdown - shift the values around based on the heap
 * @array: array of integers
 * @start: start index
 * @end: end index
 * @size: size of array
 * Return: Nothing
 */
void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = 0, child = 0, swapper = 0;

	root = start;
	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swapper = root;
		if (array[swapper] < array[child])
			swapper = child;
		if (child + 1 <= end && array[swapper] < array[child + 1])
			swapper = child + 1;
		if (swapper == root)
			return;
		else if (root != swapper)
		{
			swap(&array[root], &array[swapper], size, array);
			root = swapper;
		}
	}
}

/**
 * swap - swaps to integers.
 * @a: integer
 * @b: integer
 * @size: size of array
 * @array: array
 * Return: nothing
 */
void swap(int *a, int *b, size_t size, int *array)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

	print_array(array, size);
}

/**
 * heap_sort - function that sorts an array of integers in ascending order
 * @array: array
 * @size: size
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t end = 0;

	if (size < 2)
		return;

	h_array(array, size);
	end = size - 1;
	while (end)
	{
		if (end)
			swap(&array[0], &array[end], size, array);
		end--;
		siftdown(array, 0, end, size);
	}
}
