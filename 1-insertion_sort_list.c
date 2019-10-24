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
	listint_t *next, *aux;
	listint_t *prev;
	listint_t *n_n;
	int cont = 1;

	while (cont != 0)
	{
		cont = 0;
		for (cursor = *list; cursor->next != NULL; cursor = cursor->next)
		{
			if (cursor->n > cursor->next->n)
			{
				cont++;
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
				print_list(*list);
				break;
			}
		}
		for (; cursor->prev != NULL; cursor = cursor->prev)
		{
			if (cursor->n < cursor->prev->n)
			{
				next = cursor->prev->next;
				prev = cursor->prev->prev;
				n_n = next->next;
				aux = cursor->prev;
				aux->next = n_n;
				aux->prev = next;
				if (prev)
					prev->next = next;
				next->prev = prev;
				next->next = aux;
				if (n_n)
					n_n->prev = aux;
				print_list(*list);
			}
		}
	}
}
