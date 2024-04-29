#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *arr, size_t size1, int left, int right);
void hoare_sort(int *arr, size_t size1, int left, int right);
void quick_sort_hoare(int *arr, size_t size1);

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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *arr, size_t size1, int left, int right)
{
	int pivot, above, below;

	pivot = arr[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (arr[above] < pivot);
		do {
			below--;
		} while (arr[below] > pivot);

		if (above < below)
		{
			swap_ints(arr + above, arr + below);
			print_array(arr, size1);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *arr, size_t size1, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(arr, size1, left, right);
		hoare_sort(arr, size1, left, part - 1);
		hoare_sort(arr, size1, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *arr, size_t size1)
{
	if (arr == NULL || size1 < 2)
		return;

	hoare_sort(arr, size1, 0, size1 - 1);
}

