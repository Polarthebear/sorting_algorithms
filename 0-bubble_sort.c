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
 * bubble_sort - Main entry point
 * Description: Sort an array of ints in ascending order
 * @array: Array of integers to sort
 * @size: Size of array
 */
void bubble_sort(int *array, size_t size)
{
	bool bubbly = false;
	size_t i, leng = size;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < leng - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		leng--;
	}
}
