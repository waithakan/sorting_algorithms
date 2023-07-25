#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - sort an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array of integer
 * @size: sizes of arrays
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;
	int tmp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
