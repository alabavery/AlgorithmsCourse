/*
 * MergeSort.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: alavery
 */
#include <iostream>
using namespace std;


template <class subscriptable_1D, class subscriptable_2D>
void bubble_sort_2D(
				subscriptable_2D &twod,
				int twod_size,
				subscriptable_1D temp,
				bool(*is_greater_than)(subscriptable_1D,subscriptable_1D)
				)
{
	/* This function should be able to sort any 2d of subscriptables
	 * (e.g. 2D arrays or vectors of arrays or arrays of vectors or
	 * vectors of vectors), using any comparison function provided
	 */
	bool a_switch_made = false;
	while (true)
	{
		a_switch_made = false;
		for (int i = 0; i < twod_size - 1; i++)
		{
			if (is_greater_than(twod[i][2], twod[i+1][2]))
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

