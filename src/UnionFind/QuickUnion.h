/*
 * QuickUnion.h
 *
 *  Created on: Feb 6, 2017
 *      Author: alavery
 */

#include "IUnionFind.h"

#ifndef UNIONFIND_QUICKUNION_H_
#define UNIONFIND_QUICKUNION_H_


class QuickUnion : public IUnionFind {
protected:
	void initialize_id();
public:
	void unionize(int p, int q);
	void init(string stdinput_file_path);
	void init(int N);
	bool test_connection(int p, int q);
	int get_root(int leaf);
};


#endif /* UNIONFIND_QUICKUNION_H_ */
