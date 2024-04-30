#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *arr, size_t size, int left, int right);
void lomuto_sort(int *arr, size_t size, int left, int right);
void quick_sort(int *arr, size_t size);

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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @arr: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *arr, size_t size, int left, int right)

{
	int *pivots, above, below;

	pivots = arr + right;
	for (above = below = left; below < right; below++)
	{
		if (arr[below] < *pivots)
		{
			if (above < below)
			{
				swap_ints(arr + below, arr + above);
				print_array(arr, size);
			}
			above++;
		}
	}

	if (arr[above] > *pivots)
	{
		swap_ints(arr + above, pivots);
		print_array(arr, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *arr, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(arr, size, left, right);
		lomuto_sort(arr, size, left, part - 1);
		lomuto_sort(arr, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;

	lomuto_sort(arr, size, 0, size - 1);
}

