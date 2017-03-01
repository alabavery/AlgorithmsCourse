/*
 * MinimumSpanningTrees.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: alavery
 */
#include <iostream>
#include "Sorting/Sorting.cpp"
#include "MinimumSpanningTrees.h"

using namespace std;



MST::MST(int N, string displaytreetxtpath, int (*weighting_function)(int,int)) {
	this->N = N;
	this->uf = QuickFind();
	this->uf.init(this->N, displaytreetxtpath);
	this->weighting_function = weighting_function;
}



void GenericMST::run_algorithm()
{
	int the_union[2] = {0, 0};
	while (true) {
		this->find_next_union(the_union);

		if (the_union[0] >= 0)
		{
			this->uf.union_and_print_wrapper(the_union[0], the_union[1]);
		} else {
			break;
		}
	}
	this->uf.print_to_file();
}


void GenericMST::find_next_union(int the_union[2])
{
	int temp_union_0 = the_union[0];
	int temp_union_1 = the_union[1];
	int current_min_weight = 10000;

	for (int node_outside = 1; node_outside < this->N; node_outside++)
	{
		if (!this->uf.test_connection(node_outside, 0))
		{
			for (int node_inside = 0; node_inside < this->N; node_inside++)
			{
				if (this->uf.test_connection(node_inside, 0))
				{
					int this_weight = this->weighting_function(node_outside, node_inside);

					if (this_weight < current_min_weight)
					{
						current_min_weight = this_weight;
						the_union[0] = node_outside;
						the_union[1] = node_inside;
					}
				}
			}
		}
	}

	if (temp_union_0 == the_union[0] && temp_union_1 == the_union[1])
	{
		the_union[0] = -1;
	}
}


void MST_Krugal::run_algorithm()
{
	int ** edge_array = this->make_edge_array();
	selection_sort(edge_array, N*(N-1)/2, edge_array[0], this->compare_edges);
}


bool MST_Krugal::compare_edges(int * edge1, int * edge2)
{
	return edge1[2] > edge2[2];
}


int ** MST_Krugal::make_edge_array()
{
	int ** edge_array = new int*[N*(N-1)/2]; // (N*(N-1)/2) gives number of edges needed for one edge between each node
	int index = 0;

	for (int i = 0; i < this->N; i++)
	{
		for (int j = i+1; j < this->N; j++)
		{
			int * this_edge = new int[3];
			this_edge[0] = i, this_edge[1] = j;
			this_edge[2] = this->weighting_function(i, j);
			edge_array[index] = this_edge;
			index++;
		}
	}
	return edge_array;
}
