#include "sort.h"
#include <stdio.h>

/**
 *partition - finds partition for quick sort using
 *lomuto scheme
 *@array: array to be sorted
 *@low: lowest index
 *@high: highest index
 *@size: size of array
 *
 *Return: partition index
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int temp, p;

	p = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < p)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 *qsort - sorts a partition od an array of integers
 *@array: array to sort
 *@low: lowest index of partition
 *@high: highest index of partition
 *@size: size of array
 *
 * Return: void
 */
void fastsort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		fastsort(array, low, p - 1, size);
		fastsort(array, p + 1, high, size);
	}
}

/**
 *quick_sort - sorts an array of inteers in ascending order
 *using quick sort algorithm
 *@array: array to be sorted
 *@size: size of array
 *
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	fastsort(array, 0, size - 1, size);
}
