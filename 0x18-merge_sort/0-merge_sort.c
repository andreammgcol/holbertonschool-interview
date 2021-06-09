#include "sort.h"
/**
 * merging - merges left and right arrays
 * @array: pointer array
 * @size: size array
 * @left: pointer left
 * @right: pointer right
 **/
void merging(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);
	while (i < size_l && j < size_r)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < size_l)
		array[k++] = left[i++];
	while (j < size_r)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: pointer array
 * @size: size array
 **/
void merge_sort(int *array, size_t size)
{
	size_t middle = 0, i;
	int left[100];
	int right[100];

	if (array == NULL || size < 2)
		return;
	middle = size / 2;
	for (i = 0; i < middle; i++)
		left[i] = array[i];
	for (i = middle; i < size; i++)
		right[i - middle] = array[i];
	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merging(array, left, right, size);
}
