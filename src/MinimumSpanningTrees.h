/*
 * MinimumSpanningTrees.h
 *
 *  Created on: Feb 14, 2017
 *      Author: alavery
 */
/* For each of the MinimumSpanningTree algorithms, we start with a graph of N nodes
 * and assume that there is an edge between every pair of nodes, so we can therefore
 * use any configuration of the nodes to get our tree.
 *
 * The QuickUnion UnionFind classes can't be used for a minimum spanning tree, because
 * calling a union between any nodes p and q does not necessarily lead to an edge being
 * formed between p and q; instead it forms an edge between p's root and q's root.  So
 * if you calculate the least weight edge to be p-q, calling union(p,q) won't necessarily
 * give you that least weight edge.
 * All this to say, use QuickFind or FirstImplementation rather than QuickUnion.
 */

#include "UnionFind/QuickFind.h"

#ifndef UNIONFIND_MINIMUMSPANNINGTREES_H_
#define UNIONFIND_MINIMUMSPANNINGTREES_H_


class MST {
public:
	int N;
	QuickFind uf;
	int (*weighting_function)(int,int);
	MST(int N, string displaytreetxtpath, int (*weighting_function)(int,int));
};


//
class GenericMST: public MST {
private:
	void find_next_union(int the_union[2]);
	void run_algorithm();
public:
	GenericMST(int N, string displaytreetxtpath, int (*weighting_function)(int,int))
	: MST(N, displaytreetxtpath, weighting_function) { this->run_algorithm(); }
};



class MST_Krugal:public MST {
private:
	int ** make_edge_array();
	int * order_edge_array(int edge_array[]);
	void run_algorithm();
public:
	MST_Krugal(int N, string displaytreetxtpath, int (*weighting_function)(int,int))
	: MST(N, displaytreetxtpath, weighting_function) { this->run_algorithm(); }
};


#endif /* UNIONFIND_MINIMUMSPANNINGTREES_H_ */
