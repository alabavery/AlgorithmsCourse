/*
 * FirstImplementation.h
 *
 *  Created on: Jan 24, 2017
 *      Author: alavery
 *
 *  FirstImplementation starts with int * pointing to arrays just containing i for
 *  each i in 0 < i < N.  Union iterates through each i's array and combines, then
 *  replaces the pointers for all i's that were a part of either component involved
 *  in the union with a pointer to the new array.
 *
 *  Find just sees if the pointers in p and q spots point to the same address.
 *
 */

#ifndef FirstImplementation_H_
#define FirstImplementation_H_
#include <vector>
#include "IUnionFind.h"

using namespace std;


class FirstImplementation : public IUnionFind {
private:
	virtual void initialize_id();
public:
	void init(string stdinput_file_path);
	void init(int N, string displaytreetxtpath);
	void unionize(int p, int q);
	vector<int*> component_ptrs;
//	~FirstImplementation();
	bool test_connection(int p, int q);
	void print_components();
};



#endif /* FirstImplementation_H_ */
