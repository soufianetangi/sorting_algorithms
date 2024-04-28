#include "sort.h"

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
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *arr, size_t size1)
{
	int *count, *sorted, max, i;

	if (arr == NULL || size1 < 2)
		return;

	sorted = malloc(sizeof(int) * size1);
	if (sorted == NULL)
		return;
	max = get_max(arr, size1);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size1; i++)
		count[arr[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size1; i++)
	{
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]] -= 1;
	}

	for (i = 0; i < (int)size1; i++)
		arr[i] = sorted[i];

	free(sorted);
	free(count);
}

