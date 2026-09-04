#include "holberton.h"

/**
 * wildcmp - Compares two strings with wildcard support
 * @s1: String to compare
 * @s2: Pattern that may contain the wildcard character
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
		return (*s1 == '\0');

	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1))
			return (1);

		if (*s1 != '\0')
			return (wildcmp(s1 + 1, s2));

		return (0);
	}

	if (*s1 != '\0' && *s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
