/*
 * MinimumSpanningTrees.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: alavery
 */

#include "MinimumSpanningTrees.h"


GenericMST::GenericMST(int N, string displaytreetxtpath)
{
	this->N = N;
	this->prime_node = 0;
	this->uf = WeightedQuickUnion();
	this->uf.init(this->N, displaytreetxtpath);

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
		if (this->uf.get_root(node_outside) != this->prime_node)
		{
			for (int node_inside = 0; node_inside < this->N; node_inside++)
			{
				if (this->uf.get_root(node_inside) == this->prime_node)
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


int GenericMST::weighting_function(int p, int q) {
	return p - q;
}
