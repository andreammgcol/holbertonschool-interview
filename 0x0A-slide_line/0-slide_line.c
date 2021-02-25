#include "slide_line.h"


/**
 * left - Slide to the left
 * @line: Pointer
 * @size: Elements in array
 */
void left(int *line, size_t size)
{
	int i, tmp, current = 0;

	for (i = 0; i < (int) size && current < (int) size; i++)
	{
		while (line[current] != 0)
			current++;
		if (line[i] != 0 && i > current)
		{
			tmp = line[i];
			line[i] = line[current];
			line[current] = tmp;
		}
	}
}

/**
 * right - Slide to the right
 * @line: Pointer
 * @size: Elements in array
 */
void right(int *line, size_t size)
{
	int i, tmp, current = size - 1;

	for (i = size - 1; i >= 0 && current >= 0; i--)
	{
		while (current > 0 && line[current] != 0)
			current--;
		if (line[i] != 0 && i < (int) current)
		{
			tmp = line[i];
			line[i] = line[current];
			line[current] = tmp;
		}
	}
}

/**
 * slide_line - Slide and merge an array of integers
 * @line: Pointer
 * @size: Elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 on success, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;
	int num = 0;

	if (direction == SLIDE_LEFT)
	{
		left(line, size);
		for (i = 1; i < size && line[i] != 0; i++)
		{
			if (line[i - 1] == line[i])
			{
				line[i - 1] *= 2;
				line[i] = 0;
				num = 1;
			}
		}
		if (num)
			left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		right(line, size);
		for (i = size - 1; i > 0 && line[i - 1] != 0; i--)
		{
			if (line[i - 1] == line[i])
			{
				line[i] *= 2;
				line[i - 1] = 0;
				num = 1;
			}
		}
		if (num)
			right(line, size);
	}
	else
	{
		return (0);
	}

	return (1);
}
