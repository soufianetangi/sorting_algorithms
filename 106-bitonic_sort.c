/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *arr, size_t size1, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *arr, size_t size1, size_t start, size_t seq, char flow);
void bitonic_sort(int *arr, size_t size1);

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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *arr, size_t size1, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && arr[i] > arr[i + jump]) ||
			    (flow == DOWN && arr[i] < arr[i + jump]))
				swap_ints(arr + i, arr + i + jump);
		}
		bitonic_merge(arr, size1, start, jump, flow);
		bitonic_merge(arr, size1, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *arr, size_t size1, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size1, str);
		print_array(arr + start, seq);

		bitonic_seq(arr, size1, start, cut, UP);
		bitonic_seq(arr, size1, start + cut, cut, DOWN);
		bitonic_merge(arr, size1, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size1, str);
		print_array(arr + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *arr, size_t size1)
{
	if (arr == NULL || size1 < 2)
		return;

	bitonic_seq(arr, size1, 0, size1, UP);
}

