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
private:
	virtual void unionize(int p, int q);
public:
	virtual bool test_connection(int p, int q);
	int get_root(int leaf);
};


#endif /* UNIONFIND_QUICKUNION_H_ */
