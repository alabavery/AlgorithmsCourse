/*
 * QuickUnion.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: alavery
 */
#include <fstream>
#include <iostream>
#include "QuickUnion.h"
using namespace std;


void QuickUnion::unionize(int p, int q) {
	int p_root = this->get_root(p);
	id[p_root] = q;
}


bool QuickUnion::test_connection(int p, int q) {
	return this->get_root(p) == this->get_root(q);
}


int QuickUnion::get_root(int leaf) {
	int temp = leaf;
	while (this->id[temp] != temp) {
		temp = this->id[temp];
	}
	return temp;
}
