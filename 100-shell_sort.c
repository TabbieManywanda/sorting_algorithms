#include "sort.h"

/**
 *shell_sort - sorts an array of integers in ascending order
 *using shell sort algorithm (knuth sequence)
 *@array: array to be sorted
 *@size: size of array
 *
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int ins;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			ins = array[i];
			for (j = i; j >= gap && array[j - gap] > ins; j = j - gap)
				array[j] = array[j - gap];
			array[j] = ins;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
