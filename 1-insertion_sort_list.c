#include "sort.h"
/**
 * insertion_sort_list - sort a list in ascending order using intertion
 *
 * @list: pointer to a pointer to the head of the list
 *
 *
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *sorted = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while ((*list) != NULL)
	{
		current = (*list);
		(*list) = (*list)->next;
		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else if (current->n == sorted->n)
		{
			current->next = sorted->next;
			sorted->next = current;
			current->prev = sorted;
		}
		else
		{
			temp = sorted;
			while (temp != NULL)
			{
				if (temp->next == NULL || current->n < temp->next->n)
				{
					current->next = temp->next;
					temp->next = current;
					current->prev = temp;
					break;
				}
				temp = temp->next;
			}
		}
	}
	(*list) = sorted;
	print_list(sorted);
}
