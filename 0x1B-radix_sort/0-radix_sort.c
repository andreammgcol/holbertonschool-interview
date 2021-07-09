#include "sort.h"
/**
 * radix_sort - that sorts an array of integers in ascending
 * order using the radix sort algorithm
 * @array: array
 * @size: size
 */
void radix_sort(int *array, size_t size)
{
	int digit, i, k, j, div = 1, idx;
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	digit = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > digit)
			digit = array[i];
	}
	for (div = 1; (digit / div) > 0; div *= 10)
	{
		idx = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < (int)size; j++)
			{
				if (div == 1)
				{
					if (array[j] % 10 == i)
						temp[idx] = array[j], idx++;
				}
				else
				{
					if ((array[j] / div) % 10 == i)
						temp[idx] = array[j], idx++;
				}
			}
		}
		for (k = 0; k < (int)size; k++)
			array[k] = temp[k];
		print_array(array, size);
	}
	free(temp);
}
