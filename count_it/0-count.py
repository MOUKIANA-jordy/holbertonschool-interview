#!/usr/bin/python3
"""Count keywords in the titles of hot Reddit posts."""

import requests


def count_words(subreddit, word_list, after=None,
                counts=None, duplicates=None):
    """Print sorted keyword counts from hot Reddit post titles.

    Args:
        subreddit: Name of the subreddit to query.
        word_list: List of keywords to count.
        after: Reddit pagination token.
        counts: Dictionary containing current keyword counts.
        duplicates: Number of occurrences of each requested keyword.
    """
    if counts is None:
        counts = {}
        duplicates = {}

        for word in word_list:
            keyword = word.lower()

            if keyword:
                counts[keyword] = 0
                duplicates[keyword] = duplicates.get(keyword, 0) + 1

        if not counts:
            return

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "Holberton keyword counter"}
    params = {"limit": 100}

    if after is not None:
        params["after"] = after

    try:
        response = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False
        )

        if response.status_code != 200:
            return

        data = response.json()
        children = data["data"]["children"]
    except (requests.RequestException, ValueError, KeyError, TypeError):
        return

    for post in children:
        title = post["data"].get("title", "").lower()

        for word in title.split():
            if word in counts:
                counts[word] += duplicates[word]

    after = data["data"].get("after")

    if after is not None:
        return count_words(
            subreddit,
            word_list,
            after,
            counts,
            duplicates
        )

    results = [
        (word, count)
        for word, count in counts.items()
        if count > 0
    ]

    results.sort(key=lambda item: (-item[1], item[0]))

    for word, count in results:
        print("{}: {}".format(word, count))
