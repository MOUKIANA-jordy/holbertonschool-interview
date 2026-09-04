#!/usr/bin/python3
"""Create Pascal's triangle."""


def pascal_triangle(n):
    """Return Pascal's triangle containing n rows.

    Args:
        n: Number of rows in the triangle.

    Returns:
        A list of lists representing Pascal's triangle.
        An empty list if n is less than or equal to zero.
    """
    if n <= 0:
        return []

    triangle = []

    for row_index in range(n):
        row = [1] * (row_index + 1)

        for column in range(1, row_index):
            row[column] = (
                triangle[row_index - 1][column - 1]
                + triangle[row_index - 1][column]
            )

        triangle.append(row)

    return triangle
