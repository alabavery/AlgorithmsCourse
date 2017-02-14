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
public:
	virtual void init(string stdinput_file_path) = 0;
protected:
	int * id;
	int N;
	virtual void initialize_id() = 0;
	void default_init(string stdinput_file_path);
	void default_init(int N);
	void default_initialize_id();
	void assign_N_from_stdinput(string file_path);
	void iterate_unions_in_stdinput(string file_path);
	virtual void unionize(int p, int q) = 0;
public:
	virtual ~IUnionFind() {}
	virtual bool test_connection(int p, int q) = 0;
};



#endif /* UNIONFIND_IUNIONFIND_H_ */
