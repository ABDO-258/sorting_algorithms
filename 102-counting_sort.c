#include "sort.h"
/**
 * counting_sort - sort a list in ascending order using counting sort
 *
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 *
 *
*/
void counting_sort(int *array, size_t size)
{
	int *arr_count, *arr_sorted;
	int bigger_value, i, j;
	size_t k;

	/*check if the array is empty or have only 1 value*/
	if (array == NULL || size < 2)
		return;
	/*find the bigger value in the array*/
	bigger_value = array[0];
	for (k = 0; k < size; k++)
	{
		if (array[k] > bigger_value)
			bigger_value = array[k];
	}
	arr_count = malloc(sizeof(int) * (bigger_value + 1));
	if (arr_count == NULL)
		return;
	for (i = 0; i < (bigger_value + 1); i++)
		arr_count[i] = 0;
	for (k = 0; k < size; k++)
		arr_count[array[k]]++;
	for (i = 1; i < (bigger_value + 1); i++)
		arr_count[i] += arr_count[i - 1];
	print_array(arr_count, (bigger_value + 1));
	arr_sorted = malloc(sizeof(int) * size);
	if (arr_sorted == NULL)
	{
		free(arr_count);
		return;
	}
	for (j = size - 1; j > 0; j--)
	{
		arr_sorted[arr_count[array[j]] - 1] = array[j];
		arr_count[array[j]]--;
	}
	for (k = 0; k < size; k++)
		array[k] = arr_sorted[k];
	
	free(arr_count);
	free(arr_sorted);
}
