#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @arr: An array of integers.
 * @size1: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *arr, size_t size1)
{
	int *min;
	size_t i, j;

	if (arr == NULL || size1 < 2)
		return;

	for (i = 0; i < size1 - 1; i++)
	{
		min = arr + i;
		for (j = i + 1; j < size1; j++)
			min = (arr[j] < *min) ? (arr + j) : min;

		if ((arr + i) != min)
		{
			swap_ints(arr + i, min);
			print_array(arr, size1);
		}
	}
}

