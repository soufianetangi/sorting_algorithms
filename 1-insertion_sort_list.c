#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @nn1: A pointer to the first node to swap.
 * @nn2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **nn1, listint_t *nn2)
{
	(*nn1)->next = nn2->next;
	if (nn2->next != NULL)
		nn2->next->prev = *nn1;
	nn2->prev = (*nn1)->prev;
	nn2->next = *nn1;
	if ((*nn1)->prev != NULL)
		(*nn1)->prev->next = nn2;
	else
		*h = nn2;
	(*nn1)->prev = nn2;
	*nn1 = nn2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @lists: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **lists)
{
	listint_t *iter, *insert, *tmp;

	if (lists == NULL || *lists == NULL || (*lists)->next == NULL)
		return;

	for (iter = (*lists)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(lists, &insert, iter);
			print_list((const listint_t *)*lists);
		}
	}
}
