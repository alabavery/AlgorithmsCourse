/*
 * UnionFind.h
 *
 *  Created on: Jan 24, 2017
 *      Author: alavery
 */

#include <vector>
#ifndef UnionFind_H_
#define UnionFind_H_

using namespace std;


class UnionFind {
private:
	int N;
	void set_initial_node_pointers();
public:
	vector<int*> component_ptrs;
	UnionFind(string file_path);
	UnionFind(int N);
//	~UnionFind();
	void unionize(int p, int q);
	bool test_connection(int p, int q);
	void print_components();
};



#endif /* UnionFind_H_ */
