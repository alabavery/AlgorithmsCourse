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
	void unionize(int p, int q);
	void initialize_id();
public:
	void init(string stdinput_file_path);
	bool test_connection(int p, int q);
	int get_root(int leaf);
};


#endif /* UNIONFIND_QUICKUNION_H_ */
