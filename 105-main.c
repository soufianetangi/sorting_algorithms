#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n);
    printf("\n");
    radix_sort(arr, n);
    printf("\n");
    print_array(arr, n);
    return (0);
}
