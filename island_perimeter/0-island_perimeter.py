#!/usr/bin/python3
"""Calculate the perimeter of an island represented by a grid."""


def island_perimeter(grid):
    """Return the perimeter of the island described in grid.

    Args:
        grid: A rectangular list of lists containing 0 and 1.
              0 represents water and 1 represents land.

    Returns:
        The perimeter of the island.
    """
    if not grid or not grid[0]:
        return 0

    perimeter = 0

    for row in range(len(grid)):
        for column in range(len(grid[row])):
            if grid[row][column] == 1:
                perimeter += 4

                if row > 0 and grid[row - 1][column] == 1:
                    perimeter -= 2

                if column > 0 and grid[row][column - 1] == 1:
                    perimeter -= 2

    return perimeter
