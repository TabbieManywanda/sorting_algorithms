#include "sort.h"

/**
 *bubble_sort - sorts an array of integers
 *in ascending order using Bubble sort algorith
 *
 *@array: the array to be sorted
 *@size: size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n, new;
	int temp;

	if (array == NULL || size < 2)
		return;

	n = size;
	while (n > 0)
	{
		new = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				new = i + 1;
				print_array(array, size);
			}
		}
		n = new;
	}
}
