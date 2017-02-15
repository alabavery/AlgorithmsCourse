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


void QuickUnion::init(string stdinput_file_path) {
	this->default_init(stdinput_file_path);
}


void QuickUnion::init(int N, string displaytreetxtpath) {
	this->default_init(N, displaytreetxtpath);
}


void QuickUnion::initialize_id() {
	this->default_initialize_id();
}


void QuickUnion::unionize(int p, int q) {
	int p_root = this->get_root(p);
	id[p_root] = this->get_root(q);
}


bool QuickUnion::test_connection(int p, int q) {
	return this->get_root(p) == this->get_root(q);
}


int QuickUnion::get_root(int leaf) {
	while (this->id[leaf] != leaf) {
		this->id[leaf] = this->id[this->id[leaf]]; // shorten path length while going down path
		leaf = this->id[leaf];
	}
	return leaf;
}
