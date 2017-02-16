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
	int find_next_node();
	WeightedQuickUnion uf;
	bool check_if_done();
public:
	GenericMST(int N, string displaytreetxtpath);
};



#endif /* UNIONFIND_MINIMUMSPANNINGTREES_H_ */
