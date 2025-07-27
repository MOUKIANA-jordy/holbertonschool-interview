#!/usr/bin/python3
"""
0-rain module
"""


def rain(walls):
    """
    Calculates how many square units of water will be retained after rain.

    Args:
        walls (list): List of non-negative integers representing wall heights.

    Returns:
        int: Total units of water retained.
    """
    if not walls or len(walls) < 3:
        return 0

    left, right = 0, len(walls) - 1
    left_max, right_max = walls[left], walls[right]
    water = 0

    while left < right:
        if walls[left] < walls[right]:
            left += 1
            left_max = max(left_max, walls[left])
            water += max(0, left_max - walls[left])
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            water += max(0, right_max - walls[right])

    return water
