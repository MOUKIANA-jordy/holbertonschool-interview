#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int left, int right);
int recursive_advanced_binary(int *array, int left, int right, int value);
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
