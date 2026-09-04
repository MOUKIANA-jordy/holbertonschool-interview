#!/usr/bin/python3
"""Calculate the minimum number of coins needed to reach a total."""


def makeChange(coins, total):
    """Return the fewest number of coins needed to reach total.

    Args:
        coins: A list containing the available coin denominations.
        total: The amount to reach.

    Returns:
        The minimum number of coins needed, 0 if total is not positive,
        or -1 if the total cannot be reached.
    """
    if total <= 0:
        return 0

    if not coins:
        return -1

    denominations = set(coin for coin in coins if coin <= total)
    minimum = [total + 1] * (total + 1)
    minimum[0] = 0

    for coin in denominations:
        for amount in range(coin, total + 1):
            minimum[amount] = min(
                minimum[amount],
                minimum[amount - coin] + 1
            )

    if minimum[total] == total + 1:
        return -1

    return minimum[total]
