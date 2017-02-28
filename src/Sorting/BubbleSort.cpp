#include <iterator>
#include <iostream>
using namespace std;


int** make_2D_array(int rows, int columns)
{
	int ** array_2D = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		array_2D[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			array_2D[i][j] = rand() % 100;
		}
	}
	return array_2D;
}


template <class higher_dimension>
void print_2D(higher_dimension higher_d, int rows, int columns)
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << higher_d[i][j] << " ";
		}
		cout << endl;
	}
}


template <class lower_dimension, class higher_dimension>
void bubble_sort(
				higher_dimension &higher_d,
				int higher_d_size,
				lower_dimension temp,
				bool(*is_greater_than)(lower_dimension,lower_dimension)
				)
{
	/* This function can be used to sort any subscriptable (higher_dimension)
	 * in which the contents (lower_dimension) are of one fewer dimensions
	 * than the container (e.g., 1D array, 2D array, 2D vector..), iff
	 * the user provides a pointer to a function that can be used to compare
	 * two elements of the lower dimension.
	 */
	bool a_switch_made = false;
	while (true)
	{
		a_switch_made = false;
		for (int i = 0; i < higher_d_size - 1; i++)
		{
			if (is_greater_than(higher_d[i], higher_d[i+1]))
			{
				a_switch_made = true;
				temp = higher_d[i];
				higher_d[i] = higher_d[i+1];
				higher_d[i+1] = temp;
			}
		}
		if (!a_switch_made) {
			break;
		}
	}
}


template <class lower_dimension, class higher_dimension>
void selection_sort(
				higher_dimension &higher_d,
				int higher_d_size,
				lower_dimension temp,
				bool(*is_greater_than)(lower_dimension,lower_dimension)
				)
{
	lower_dimension lowest = higher_d[0];
	int lowest_index = 0;
	int current_front = 0;

	while (current_front != higher_d_size - 1)
	{
		lowest = higher_d[current_front];
		for (int i = current_front; i < higher_d_size; i++)
		{
			if (is_greater_than(lowest, higher_d[i]))
			{
				lowest = higher_d[i];
				lowest_index = i;
			}
		}
		temp = higher_d[current_front];
		higher_d[current_front] = lowest;
		higher_d[lowest_index] = temp;
		current_front++;
	}
}
