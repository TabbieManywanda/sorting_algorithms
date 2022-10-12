#include "sort.h"

/**
 *selection_sort - sorts an array of integers
 *in ascending order using selection sort algorithm
 *@array: array to be sorted
 *@size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, m;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m])
				m = j;
		}
		if (i != m)
		{
			temp = array[i];
			array[i] = array[m];
			array[m] = temp;
			print_array(array, size);
		}
	}
}
