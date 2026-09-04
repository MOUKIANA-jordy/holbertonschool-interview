#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 * @array: Array to print
 * @size: Number of elements in the array
 */
void print_array(const int *array, size_t size)
{
	size_t index;

	index = 0;

	while (array != NULL && index < size)
	{
		if (index > 0)
			printf(", ");

		printf("%d", array[index]);
		index++;
	}

	printf("\n");
}
