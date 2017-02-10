/*
 * QuickFind.h
 *
 *  Created on: Feb 6, 2017
 *      Author: alavery
 */

#ifndef UNIONFIND_QUICKFIND_H_
#define UNIONFIND_QUICKFIND_H_

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "IUnionFind.h"
using namespace std;


class QuickFind : public IUnionFind {
private:
	virtual void unionize(int p, int q);
	virtual void initialize_id();
public:
	void init(string stdinput_file_path);
	virtual bool test_connection(int p, int q);
};

#endif /* UNIONFIND_QUICKFIND_H_ */
