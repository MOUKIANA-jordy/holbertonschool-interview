#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * word_matches - Checks whether two words match
 * @first: Pointer to the first word
 * @second: Pointer to the second word
 * @length: Number of characters to compare
 *
 * Return: 1 if the words match, otherwise 0
 */
static int word_matches(const char *first, const char *second,
			size_t length)
{
	size_t index;

	for (index = 0; index < length; index++)
	{
		if (first[index] != second[index])
			return (0);
	}

	return (1);
}

/**
 * valid_substring - Checks a possible substring
 * @start: Beginning of the substring
 * @words: Array of words to find
 * @nb_words: Number of words
 * @word_length: Length of each word
 * @used: Array tracking the words already used
 *
 * Return: 1 if the substring is valid, otherwise 0
 */
static int valid_substring(const char *start, const char **words,
			   int nb_words, size_t word_length, int *used)
{
	int position;
	int word;
	int found;

	for (word = 0; word < nb_words; word++)
		used[word] = 0;

	for (position = 0; position < nb_words; position++)
	{
		found = 0;

		for (word = 0; word < nb_words; word++)
		{
			if (!used[word] &&
			    word_matches(start + position * word_length,
					 words[word], word_length))
			{
				used[word] = 1;
				found = 1;
				break;
			}
		}

		if (!found)
			return (0);
	}

	return (1);
}

/**
 * valid_arguments - Checks the arguments and word lengths
 * @s: String to scan
 * @words: Array of words
 * @nb_words: Number of words
 * @word_length: Address at which to store the word length
 *
 * Return: 1 if the arguments are valid, otherwise 0
 */
static int valid_arguments(const char *s, const char **words,
			   int nb_words, size_t *word_length)
{
	int index;

	if (s == NULL || words == NULL || nb_words <= 0)
		return (0);

	if (words[0] == NULL || words[0][0] == '\0')
		return (0);

	*word_length = strlen(words[0]);

	for (index = 1; index < nb_words; index++)
	{
		if (words[index] == NULL)
			return (0);

		if (strlen(words[index]) != *word_length)
			return (0);
	}

	return (1);
}

/**
 * collect_indices - Collects the valid starting indices
 * @s: String to scan
 * @words: Array of words
 * @nb_words: Number of words
 * @word_length: Length of each word
 * @possible: Number of possible starting positions
 * @indices: Array in which to store the indices
 * @used: Array tracking the words already used
 *
 * Return: Number of indices found
 */
static int collect_indices(const char *s, const char **words,
			   int nb_words, size_t word_length,
			   size_t possible, int *indices, int *used)
{
	size_t index;
	int count = 0;

	for (index = 0; index < possible; index++)
	{
		if (valid_substring(s + index, words, nb_words,
				    word_length, used))
		{
			indices[count] = (int)index;
			count++;
		}
	}

	return (count);
}

/**
 * find_substring - Finds concatenations of a list of words
 * @s: String to scan
 * @words: Array of words to concatenate
 * @nb_words: Number of words
 * @n: Address at which to store the number of results
 *
 * Return: Allocated array of indices, or NULL if none is found
 */
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n)
{
	size_t str_len, word_len, total_len, possible;
	int *indices, *used;

	if (n == NULL)
		return (NULL);

	*n = 0;
	if (!valid_arguments(s, words, nb_words, &word_len))
		return (NULL);

	str_len = strlen(s);
	total_len = word_len * nb_words;
	if (total_len > str_len)
		return (NULL);

	possible = str_len - total_len + 1;
	indices = malloc(sizeof(*indices) * possible);
	if (indices == NULL)
		return (NULL);

	used = malloc(sizeof(*used) * nb_words);
	if (used == NULL)
	{
		free(indices);
		return (NULL);
	}

	*n = collect_indices(s, words, nb_words, word_len,
			     possible, indices, used);
	free(used);

	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}

	return (indices);
}
