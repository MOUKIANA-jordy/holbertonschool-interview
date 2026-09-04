#!/usr/bin/python3
"""Rotate a square matrix 90 degrees clockwise."""


def rotate_2d_matrix(matrix):
    """Rotate an n x n matrix 90 degrees clockwise in place."""
    size = len(matrix)

    # Transpose the matrix
    for row in range(size):
        for column in range(row + 1, size):
            matrix[row][column], matrix[column][row] = (
                matrix[column][row],
                matrix[row][column]
            )

    # Reverse every row
    for row in matrix:
        row.reverse()
