/*
 * MergeSort.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: alavery
 */
#include <iostream>
using namespace std;




template <class lower_dimension, class higher_dimension>
void bubble_sort_2D(
				higher_dimension &twod,
				int twod_size,
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
		for (int i = 0; i < twod_size - 1; i++)
		{
			if (is_greater_than(twod[i], twod[i+1]))
			{
				a_switch_made = true;
				temp = twod[i];
				twod[i] = twod[i+1];
				twod[i+1] = temp;
			}
		}
		if (!a_switch_made) {
			break;
		}
	}
}
