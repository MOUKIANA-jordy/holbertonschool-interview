#!/usr/bin/python3
"""
Recursive count of words in hot articles titles from Reddit
"""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Queries the Reddit API recursively, counts occurrences of given keywords
    in the titles of all hot articles, and prints them sorted.

    - subreddit: str, name of subreddit
    - word_list: list of keywords (case-insensitive)
    """
    # Initialisation des compteurs au premier appel
    if counts is None:
        # Normaliser en minuscule, gérer les doublons
        counts = {}
        for w in word_list:
            lw = w.lower()
            counts[lw] = counts.get(lw, 0)

    # Préparer l'URL
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "Mozilla/5.0"}
    params = {"after": after, "limit": 100}

    # Requête à l'API Reddit
    resp = requests.get(url, headers=headers, params=params, allow_redirects=False)
    if resp.status_code != 200:
        return  # Subreddit invalide → ne rien afficher

    data = resp.json().get("data", {})
    children = data.get("children", [])

    # Parcours des posts
    for post in children:
        title_words = post.get("data", {}).get("title", "").lower().split()
        for target in counts.keys():
            # Compter uniquement les mots exacts (exclure java dans javascript)
            counts[target] += sum(1 for w in title_words if w == target)

    # Pagination : appel récursif s'il y a encore des posts
    after = data.get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    # Tri final et affichage
    sorted_counts = sorted(
        [(word, num) for word, num in counts.items() if num > 0],
        key=lambda x: (-x[1], x[0])
    )

    for word, num in sorted_counts:
        print(f"{word}: {num}")

