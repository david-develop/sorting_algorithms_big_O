#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: unsorted list of integers
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cursor;
	listint_t *next;
	listint_t *prev;
	listint_t *n_n, *p_p;
	int cont = 1;

	while (cont != 0)
	{
		cont = 0;
		for (cursor = *list; cursor->next != NULL; cursor = cursor->next)
		{
			if (cursor->n > cursor->next->n)
			{
				cont = 1;
				next = cursor->next;
				prev = cursor->prev;
				n_n = next->next;
				cursor->next = n_n;
				cursor->prev = next;
				if (prev)
					prev->next = next;
				next->prev = prev;
				next->next = cursor;
				if (n_n)
					n_n->prev = cursor;
				cursor = cursor->prev;
				print_list(*list);
				break;
			}
		}
		for (; cursor && cursor->prev; cursor = cursor->prev)
		{
			if (cursor->n < cursor->prev->n)
			{
				next = cursor->next;
				prev = cursor->prev;
				p_p = prev->prev;
				cursor->next = prev;
				cursor->prev = p_p;
				if (p_p)
					p_p->next = cursor;
				if (next)
					next->prev = prev;
				prev->next = next;
				prev->prev = cursor;
				cursor = cursor->next;
				if (cursor->prev->prev != NULL)
				{
					cont = 1;
					print_list(*list);
				}
				else
					cont = 2;
			}
		}
		if (cursor->prev == NULL)
		{
			*list = cursor;
			if (cont != 1 && cont != 0)
				print_list(*list);
		}
	}
}
