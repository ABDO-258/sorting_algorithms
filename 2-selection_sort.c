#include "sort.h"
/**
 * selection_sort - sort an array of integers in ascending order
 *
 * @array: the array to be sorted
 * @size:size of the array to be sorted
 *
 *
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, temp;
	int min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (k = i + 1; k < size  ; k++)
		{
			if (array[k] <= min)
			{
				min = array[k];
				j = k;
			}
		}
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
		print_array(array, size);

	}
}
