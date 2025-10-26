#!/usr/bin/python3
"""
0-island_perimeter
Module that defines a function to calculate the perimeter of an island.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.

    Args:
        grid (list of list of int): 2D grid where 0 represents water and 1 represents land.

    Returns:
        int: Perimeter of the island.
    """
    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Check all four directions
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1  # Top
                if i == rows - 1 or grid[i + 1][j] == 0:
                    perimeter += 1  # Bottom
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1  # Left
                if j == cols - 1 or grid[i][j + 1] == 0:
                    perimeter += 1  # Right

    return perimeter

