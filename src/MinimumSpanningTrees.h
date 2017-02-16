/*
 * MinimumSpanningTrees.h
 *
 *  Created on: Feb 14, 2017
 *      Author: alavery
 */

#include "UnionFind/WeightedQuickUnion.h"

#ifndef UNIONFIND_MINIMUMSPANNINGTREES_H_
#define UNIONFIND_MINIMUMSPANNINGTREES_H_


class GenericMST {
private:
	int N;
	int prime_node;
	void find_next_union(int the_union[2]);
	WeightedQuickUnion uf;
	//int weighting_function(int p, int q);
	int (*weighting_function)(int,int);
public:
	GenericMST(int N, string displaytreetxtpath, int (*weighting_function)(int,int));
};



#endif /* UNIONFIND_MINIMUMSPANNINGTREES_H_ */
