#include "sort.h"

void swap_(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Main entry point
 * Description: Arrange a subset of an integer array using
 *		the lomuto partition scheme (last element as pivot).
 * @array: The integer array
 * @size: The array's size.
 * @left: The subset's initial index for ordering.
 * @right: The subset's final index for ordering.
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *swivel, above, below;

	swivel = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *swivel)
		{
			if (above < below)
			{
				swap_(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *swivel)
	{
		swap_(array + above, swivel);
		print_array(array, size);
	}
	return (above);
}


/**
 * lomuto_sort - Main entry point
 * Description: Use recursion to implement the quicksort method.
 * @array: An array to be sorted with integers
 * @size: The array's size.
 * @left: The starting index of the array partition to order.
 * @right: The finishing index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}


/**
 * quick_sort - Main entry point
 * Description: Use the quicksort algorithm to sort
 *		an array of integers in ascending order.
 * @array: An integer array.
 * @size: The array's size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
