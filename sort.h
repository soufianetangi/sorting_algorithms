#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helper functions */
void print_array(const int *arr, size_t size1);
void print_list(const listint_t *lists);

/* Sorting algoritms */
void bubble_sort(int *arr, size_t size1);
void insertion_sort_list(listint_t **lists);
void selection_sort(int *arr, size_t size1);
void quick_sort(int *arr, size_t size);
void shell_sort(int *arr, size_t size1);
void cocktail_sort_list(listint_t **lists);
void counting_sort(int *arr, size_t size1);
void merge_sort(int *arr, size_t size1);
void heap_sort(int *arr, size_t size1);
void radix_sort(int *arr, size_t size1);
void bitonic_sort(int *arr, size_t size1);
void quick_sort_hoare(int *arr, size_t size1);

#endif /* SORT_H */

