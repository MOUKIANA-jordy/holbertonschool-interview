#include <stdlib.h>
#include "holberton.h"

/**
 * string_length - Calculates the length of a string
 * @str: String to measure
 *
 * Return: Length of the string
 */
int string_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * print_error - Prints Error and exits with status 98
 */
void print_error(void)
{
	char *message = "Error\n";
	int index = 0;

	while (message[index] != '\0')
	{
		_putchar(message[index]);
		index++;
	}

	exit(98);
}

/**
 * check_number - Checks whether a string contains only digits
 * @number: String to check
 *
 * Return: 1 if the string contains only digits, otherwise 0
 */
int check_number(char *number)
{
	int index = 0;

	if (number[0] == '\0')
		return (0);

	while (number[index] != '\0')
	{
		if (number[index] < '0' || number[index] > '9')
			return (0);

		index++;
	}

	return (1);
}

/**
 * initialize_array - Initializes an integer array with zeros
 * @array: Array to initialize
 * @size: Size of the array
 */
void initialize_array(int *array, int size)
{
	int index;

	for (index = 0; index < size; index++)
		array[index] = 0;
}

/**
 * multiply_numbers - Multiplies two positive numbers
 * @num1: First number
 * @num2: Second number
 *
 * Return: Pointer to the array containing the result
 */
int *multiply_numbers(char *num1, char *num2)
{
	int len1, len2, index1, index2;
	int digit1, digit2, position;
	int *result;

	len1 = string_length(num1);
	len2 = string_length(num2);

	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
		print_error();

	initialize_array(result, len1 + len2);

	for (index1 = len1 - 1; index1 >= 0; index1--)
	{
		digit1 = num1[index1] - '0';

		for (index2 = len2 - 1; index2 >= 0; index2--)
		{
			digit2 = num2[index2] - '0';
			position = index1 + index2 + 1;

			result[position] += digit1 * digit2;
			result[position - 1] += result[position] / 10;
			result[position] %= 10;
		}
	}

	return (result);
}

/**
 * print_result - Prints the result of the multiplication
 * @result: Array containing the result
 * @size: Size of the result array
 */
void print_result(int *result, int size)
{
	int index = 0;

	while (index < size - 1 && result[index] == 0)
		index++;

	while (index < size)
	{
		_putchar(result[index] + '0');
		index++;
	}

	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0 on success
 */
int main(int argc, char **argv)
{
	int len1, len2;
	int *result;

	if (argc != 3)
		print_error();

	if (!check_number(argv[1]) || !check_number(argv[2]))
		print_error();

	len1 = string_length(argv[1]);
	len2 = string_length(argv[2]);

	result = multiply_numbers(argv[1], argv[2]);
	print_result(result, len1 + len2);

	free(result);

	return (0);
}
