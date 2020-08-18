#include "sandpiles.h"

/**
 * print_grid - function that print a sandpiles
 * @grid: grid
 * Return: nothing
*/
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - function that check if a sandpiles is stable
 * @grid1: grid to check
 * Return: 1 if not stable
*/
int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * sum_grid - function that sum two grids
 * @grid1: first grid to sum
 * @grid2: second grid to sum
*/
void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * toppling - function that toppling to my neighbors
 * @grid1: grid
 * Return: nothing
*/
void toppling(int grid1[3][3])
{
	int gridnext[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
	};
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3)
			{
				grid1[x][y] -= 4;
				if (x - 1 >= 0 && x - 1 < 3)
					gridnext[x - 1][y] += 1;
				if (y - 1 >= 0 && y - 1 < 3)
					gridnext[x][y - 1] += 1;
				if (x + 1 >= 0 && x + 1 < 3)
					gridnext[x + 1][y] += 1;
				if (y + 1 >= 0 && y + 1 < 3)
					gridnext[x][y + 1] += 1;
			}
		}
	}
	sum_grid(grid1, gridnext);
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: first grid to sum
 * @grid2: second grid to sum
 * Return: nothing
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grid(grid1, grid2);
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		toppling(grid1);
	}
}
