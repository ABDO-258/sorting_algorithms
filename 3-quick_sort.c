#include "sort.h"

/**
 * partition - sort an array of integers in ascending using a pivot
 *
 * @array: the array to be sorted
 * @low:start of the array
 * @size:size of the array
 *
 * Return: value of x + 1
*/
int partition(int *array, size_t low, size_t size)
{
	size_t x, y, temp = 0;
	int pivot = array[size - 1];

	print_array(array, size);

	/*printf("+++++++%d+++++\n", array[size - 1]);*/
	y = low;
	x = low - 1;
	while (y < size)
	{
		if (array[y] > pivot)
			y++;
		else if (array[y] <= pivot)
		{
			x++;
			temp = array[y];
			array[y] = array[x];
			array[x] = temp;
			y++;

		}
	}
	return (x + 1);
}
/**
 * Lomuto - sort an array of integers in ascending order recursively
 *
 * @array: the array to be sorted
 * @min:start of the array
 * @max:end of the array
 *
 *
*/
void Lomuto(int *array, size_t min, size_t max)
{
	int array_partition;

	if (min < max)
	{
		array_partition = partition(array, min, max);

		/* quick sort elements on the left recursively*/
		Lomuto(array, min, array_partition - 1);

		/* quick sort elements on the right recursively*/
		Lomuto(array, array_partition, max);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 *
 * @array: the array to be sorted
 * @size:size of the array to be sorted
 *
 *
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	Lomuto(array, 0, size);

}
