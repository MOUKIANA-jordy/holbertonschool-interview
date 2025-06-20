#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - Determines whether a cell should be a space or not.
 * @row: The current row index.
 * @col: The current column index.
 *
 * Return: 1 if the cell is a hole, 0 otherwise.
 */
int is_hole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger sponge at a given recursion level.
 * @level: The recursion level of the sponge.
 */
void menger(int level)
{
	if (level < 0)
		return;

	int size = pow(3, level);

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (is_hole(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}

