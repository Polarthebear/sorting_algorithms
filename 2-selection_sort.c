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
 * selection_sort - Main entry point
 * Description: Sort an array of ints n ascending order
 *		using the selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_(array + i, min);
			print_array(array, size);
		}
	}
}
