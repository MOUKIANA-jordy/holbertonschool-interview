#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the largest value in an array
 * @array: Array of integers
 * @size: Number of elements in the array
 *
 * Return: Largest value
 */
static int get_max(const int *array, size_t size)
{
	size_t index;
	int maximum;

	maximum = array[0];

	for (index = 1; index < size; index++)
	{
		if (array[index] > maximum)
			maximum = array[index];
	}

	return (maximum);
}

/**
 * sort_digit - Sorts an array according to one significant digit
 * @array: Array to sort
 * @buffer: Temporary array
 * @size: Number of elements in the array
 * @digit: Current significant digit
 */
static void sort_digit(int *array, int *buffer, size_t size,
		       unsigned long digit)
{
	size_t count[10] = {0};
	size_t index;
	size_t position;
	int value;

	for (index = 0; index < size; index++)
	{
		value = (array[index] / digit) % 10;
		count[value]++;
	}

	for (index = 1; index < 10; index++)
		count[index] += count[index - 1];

	index = size;

	while (index > 0)
	{
		index--;
		value = (array[index] / digit) % 10;
		position = --count[value];
		buffer[position] = array[index];
	}

	for (index = 0; index < size; index++)
		array[index] = buffer[index];
}

/**
 * radix_sort - Sorts an array using the LSD Radix Sort algorithm
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	unsigned long digit;
	int maximum;
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	maximum = get_max(array, size);

	for (digit = 1; maximum / digit > 0; digit *= 10)
	{
		sort_digit(array, buffer, size, digit);
		print_array(array, size);
	}

	free(buffer);
}
