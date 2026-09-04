#!/usr/bin/python3
"""Determine the winner of the Prime Game."""


def build_prime_counts(limit):
    """Return the cumulative number of primes up to each value."""
    is_prime = [True] * (limit + 1)
    prime_counts = [0] * (limit + 1)

    is_prime[0] = False

    if limit >= 1:
        is_prime[1] = False

    number = 2

    while number * number <= limit:
        if is_prime[number]:
            multiple = number * number

            while multiple <= limit:
                is_prime[multiple] = False
                multiple += number

        number += 1

    for number in range(1, limit + 1):
        prime_counts[number] = prime_counts[number - 1]

        if is_prime[number]:
            prime_counts[number] += 1

    return prime_counts


def isWinner(x, nums):
    """Return the winner of the Prime Game."""
    if x <= 0 or not nums:
        return None

    rounds = min(x, len(nums))
    highest = max(nums[:rounds])

    if highest < 2:
        return "Ben"

    prime_counts = build_prime_counts(highest)
    maria_wins = 0
    ben_wins = 0

    for index in range(rounds):
        number = nums[index]

        if number < 2 or prime_counts[number] % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"

    if ben_wins > maria_wins:
        return "Ben"

    return None
