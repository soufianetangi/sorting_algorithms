#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *lists)
{
	int i;

	i = 0;
	while (lists)
	{
		if (i > 0)
			printf(", ");
		printf("%d", lists->n);
		++i;
		lists = lists->next;
	}
	printf("\n");
}

