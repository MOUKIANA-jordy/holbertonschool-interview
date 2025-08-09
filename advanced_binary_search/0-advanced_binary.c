#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: The starting index
 * @right: The ending index
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_advanced_binary -Helper function to perform advanced binary search
 * @array: The array to be searched
 * @left: The starting index of the subarray
 * @right: The ending index of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int recursive_advanced_binary(int *array, int left, int right, int value)
{
	int mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return (mid);

	if (array[mid] >= value)
		return (recursive_advanced_binary(array, left, mid, value));
	return (recursive_advanced_binary(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if value is not present or
 *         array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursive_advanced_binary(array, 0, size - 1, value));
}
