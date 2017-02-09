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
	void init(string stdinput_file_path);
protected:
	int * id;
	int N;
private:
	virtual void unionize(int p, int q) = 0;
	void assign_N_from_stdinput(string file_path);
	void initialize_id();
	void iterate_unions_in_stdinput(string file_path);
public:
	virtual ~IUnionFind() {}
	virtual bool test_connection(int p, int q) = 0;
};



#endif /* UNIONFIND_IUNIONFIND_H_ */
