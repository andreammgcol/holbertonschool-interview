#include "menger.h"

/**
 * menger - Function that draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * Return:
 */

void menger(int level)
{
	int i, j, size, width, height, flag = 1;
	char c_print;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			width = i;
			height = j;

			while (flag == 1)
			{
				if (width == 0 || height == 0)
				{
					c_print = '#';
					flag = 0;

				}
				else if (width % 3 == 1 && height % 3 == 1)
				{
					c_print = ' ';
					flag = 0;
				}

				width = width / 3;
				height = height / 3;
			}
			printf("%c", c_print);
			flag = 1;
		}
		printf("\n");
	}
}
