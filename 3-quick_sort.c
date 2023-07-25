#include "sort.h"
#include <stdio.h>

/**
 * partition - find the partitions for the quicksort using the Lomuto scheme
 * @array: arrays to sort
 *
 * @lo: lowest indexes of the partition to sort
 * @hi: highest indexes of the partition to sort
 * @size: sizes of the array
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sort a partition of an array of integers
 * @array: array to sort
 *
 * @lo: lowest indexes of the partition to sort
 * @hi: highest indexes of the partition to sort
 * @size: size of the arrays
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pi;

	if (lo < hi)
	{
		pi = partition(array, lo, hi, size);
		quicksort(array, lo, pi - 1, size);
		quicksort(array, pi + 1, hi, size);

	}
}

/**
 * quick_sort - sort an array of integers in ascending order using the
 * Quick sort algorithms
 *
 * @array: The array to be sorted
 * @size: The sizes of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
