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
			sorted = current;
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
					break;
				}
				temp = temp->next;
			}
		}
		print_list(sorted);
	}
}
