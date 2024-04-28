#include "sort.h"

int get_max(int *arr, int size1);
void radix_counting_sort(int *arr, size_t size1, int sig, int *buff);
void radix_sort(int *arr, size_t size1);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *arr, int size1)
{
	int max, i;

	for (max = arr[0], i = 1; i < size1; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *arr, size_t size1, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size1; i++)
		count[(arr[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size1 - 1; (int)i >= 0; i--)
	{
		buff[count[(arr[i] / sig) % 10] - 1] = arr[i];
		count[(arr[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size1; i++)
		arr[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *arr, size_t size1)
{
	int max, sig, *buff;

	if (arr == NULL || size1 < 2)
		return;

	buff = malloc(sizeof(int) * size1);
	if (buff == NULL)
		return;

	max = get_max(arr, size1);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(arr, size1, sig, buff);
		print_array(arr, size1);
	}

	free(buff);
}

