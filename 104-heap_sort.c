#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *arr, size_t size1, size_t base, size_t root);
void heap_sort(int *arr, size_t size1);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *arr, size_t size1, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && arr[left] > arr[large])
		large = left;
	if (right < base && arr[right] > arr[large])
		large = right;

	if (large != root)
	{
		swap_ints(arr + root, arr + large);
		print_array(arr, size1);
		max_heapify(arr, size1, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *arr, size_t size1)
{
	int i;

	if (arr == NULL || size1 < 2)
		return;

	for (i = (size1 / 2) - 1; i >= 0; i--)
		max_heapify(arr, size1, size1, i);

	for (i = size1 - 1; i > 0; i--)
	{
		swap_ints(arr, arr + i);
		print_array(arr, size1);
		max_heapify(arr, size1, i, 0);
	}
}

