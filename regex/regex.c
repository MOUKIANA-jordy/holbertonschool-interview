#include "regex.h"

/**
 * regex_match - Checks whether a pattern matches a string
 * @str: String to scan
 * @pattern: Regular expression to compare
 *
 * Return: 1 if the pattern matches the string, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	int matches;

	if (*pattern == '\0')
		return (*str == '\0');

	matches = (*str != '\0' &&
		   (*pattern == '.' || *pattern == *str));

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);

		if (matches)
			return (regex_match(str + 1, pattern));

		return (0);
	}

	if (matches)
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
