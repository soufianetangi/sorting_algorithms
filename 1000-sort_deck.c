#include "deck.h"

int _strcmp(const char *ss1, const char *ss2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck1);
void insertion_sort_deck_value(deck_node_t **deck1);
void sort_deck(deck_node_t **deck1);

/**
 * _strcmp - Compares two strings.
 * @ss1: The first string to be compared.
 * @ss2: The second string to be compared.
 *
 * Return: Positive byte difference if ss1 > ss2
 *         0 if ss1 == ss2
 *         Negative byte difference if ss1 < ss2
 */
int _strcmp(const char *ss1, const char *ss2)
{
	while (*ss1 && *ss2 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}

	if (*ss1 != *ss2)
		return (*ss1 - *ss2);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck1 of cards from spades to diamonds.
 * @deck1: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck1)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck1)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck1 = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck1 of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck1: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck1)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck1)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_value(insert) > get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck1 = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck1 of cards from ace to king and
 *             from spades to diamonds.
 * @deck1: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck1)
{
	if (deck1 == NULL || *deck1 == NULL || (*deck1)->next == NULL)
		return;

	insertion_sort_deck_kind(deck1);
	insertion_sort_deck_value(deck1);
}

