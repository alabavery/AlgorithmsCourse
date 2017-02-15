/*
 * IUnionFind.h
 *
 *  Created on: Feb 7, 2017
 *      Author: alavery
 */

#ifndef UNIONFIND_IUNIONFIND_H_
#define UNIONFIND_IUNIONFIND_H_

#include <fstream>
#include <iostream>
using namespace std;


class IUnionFind {
protected:
	int * id;
	int N;
	virtual void initialize_id() = 0;
	void default_init(string stdinput_file_path);
	void default_init(int N, string displaytreetxtpath);
	void default_initialize_id();
	void assign_N_from_stdinput(string file_path);
	void iterate_unions_in_stdinput(string file_path);
	virtual void unionize(int p, int q) = 0;
	string displaytreetxtpath;
public:
	virtual ~IUnionFind() {}
	virtual bool test_connection(int p, int q) = 0;
	virtual void init(string stdinput_file_path) = 0;
	virtual void init(int N, string displaytreetxtpath) = 0;
	void print_N_to_file();
	void union_and_print_wrapper(int p, int q);
};



#endif /* UNIONFIND_IUNIONFIND_H_ */
