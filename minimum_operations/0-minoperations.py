#!/usr/bin/python3
"""
This module calculates the minimum number of operations
to obtain n characters 'H' using Copy All and Paste only.
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to
    result in exactly n H characters in a file.

    Args:
        n (int): Target number of H characters

    Returns:
        int: Minimum number of operations, or 0 if impossible
    """
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
