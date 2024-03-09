#include "sort.h"

/**
 * swap_ - Main entry point
 * Description: Swaps two integers that are in an array
 * @a: First int to swap
 * @b: Second int to swap
 */
void swap_(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Main entry point
 * Description: Using the shell sort algorithm,
 *		sort an array of integers in ascending order.
 * @array: Array of integers
 * @size: Size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, n, m;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (n = gap; n < size; n++)
		{
			m = n;
			while (m >= gap && array[m - gap] > array[m])
			{
				swap_(array + m, array + (m - gap));
				m -= gap;
			}
		}
		print_array(array, size);
	}
}
