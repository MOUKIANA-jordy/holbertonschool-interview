#include "slide_line.h"

/**
 * merge_line - merges numbers in line towards left or right
 * @line: pointer to array of integers
 * @size: number of elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 */
static void merge_line(int *line, size_t size, int direction)
{
    size_t i, j;

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
                continue;
            for (j = i + 1; j < size; j++)
            {
                if (line[j] == 0)
                    continue;
                if (line[j] == line[i])
                {
                    line[i] *= 2;
                    line[j] = 0;
                }
                break;
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1; i < size; i--)
        {
            if (line[i] == 0)
                continue;
            for (j = i - 1; j < size; j--)
            {
                if (line[j] == 0)
                    continue;
                if (line[j] == line[i])
                {
                    line[i] *= 2;
                    line[j] = 0;
                }
                break;
            }
        }
    }
}

/**
 * compress_line - moves all non-zero elements to the direction
 * @line: pointer to array of integers
 * @size: number of elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 */
static void compress_line(int *line, size_t size, int direction)
{
    int buffer[size];
    size_t i, j = 0;

    for (i = 0; i < size; i++)
        buffer[i] = 0;

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
            if (line[i] != 0)
                buffer[j++] = line[i];
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size; i-- > 0;)
            if (line[i] != 0)
                buffer[size - 1 - j++] = line[i];
    }

    for (i = 0; i < size; i++)
        line[i] = buffer[i];
}

/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to array of integers
 * @size: number of elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    compress_line(line, size, direction);
    merge_line(line, size, direction);
    compress_line(line, size, direction);

    return (1);
}
