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
 * bubble_sort - Sort an array of integers in ascending order.
 * @arr: An array of integers to sort.
 * @size1: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *arr, size_t size1)
{
	size_t i, len = size1;
	bool bubly = false;

	if (arr == NULL || size1 < 2)
		return;

	while (bubly == false)
	{
		bubly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap_ints(arr + i, arr + i + 1);
				print_array(arr, size1);
				bubly = false;
			}
		}
		len--;
	}
}

