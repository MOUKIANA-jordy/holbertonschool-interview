#!/usr/bin/python3

"""
Determines if all boxes can be unlocked.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.

    Args:
        boxes (list of lists): A list where each index represents a box,
        and each element is a list of keys found in that box.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    opened = set([0])
    keys = set(boxes[0])

    while keys:
        key = keys.pop()
        if key < n and key not in opened:
            opened.add(key)
            keys.update(boxes[key])

    return len(opened) == n
