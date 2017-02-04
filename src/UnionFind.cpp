/*
 * UnionFind.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: alavery
 */
#include <vector>
#include <stdlib.h>
#include "UnionFind.h"
#include <iostream>
#include <fstream>
using namespace std;



UnionFind::UnionFind(string file_path) {
	ifstream std_input_stream(file_path);
	string sz_a_line;

	if (std_input_stream.is_open()) {
		getline(std_input_stream, sz_a_line);
		this->N = stoi(sz_a_line);
		this->set_initial_node_pointers();

		while ( getline (std_input_stream, sz_a_line) ) {
			int first_node = stoi(sz_a_line.substr(0,2));
			int second_node = stoi(sz_a_line.substr(2));
			this->unionize(first_node, second_node);
		}
	}
	std_input_stream.close();

}

UnionFind::UnionFind(int N) {
	this->N = N;
	this->set_initial_node_pointers();
}


//
//UnionFind::~UnionFind()
//{
////	for (int i = 0; i < this->component_ptrs.size(); ++i)
////	{
////		if (this->component_ptrs[i])
////			delete [] component_ptrs[i];
////	}
//}


void UnionFind::set_initial_node_pointers() {

	for (int i = 0; i < N; i++) {
		int* this_component = new int[2];
		this_component[0] = 1;
		this_component[1] = i;
		this->component_ptrs.push_back(this_component);
	}
}


void UnionFind::unionize(int p, int q) {

	if (this->component_ptrs[p] == this->component_ptrs[q]) {
		return;
	}

	int combined_size = this->component_ptrs[p][0] + this->component_ptrs[q][0];
	int* combined_components = new int[combined_size + 1];
	combined_components[0] = combined_size; // stash its size in the 0 index spot

	for (int i = 1; i <= this->component_ptrs[p][0]; i++) {
		combined_components[i] = this->component_ptrs[p][i];
	}
	for (int i = 1; i <= this->component_ptrs[q][0]; i++) {
		combined_components[i + this->component_ptrs[p][0]] = this->component_ptrs[q][i];
	}

	delete [] this->component_ptrs[q];
	delete [] this->component_ptrs[p];

	for (int i = 1; i <= combined_size; i++) {
		this->component_ptrs[combined_components[i]] = combined_components;
	}
}


bool UnionFind::test_connection(int p, int q) {
	if (this->component_ptrs[p] == this->component_ptrs[q]) return true;
	else return false;
}



void UnionFind::print_components() {
	cout << "______ Contents of component_ptrs, by index: _______" << endl;
	for (int i = 0; i < this->N; i++) {
		cout << i << " index contains an int* pointing to " << this->component_ptrs[i] << ", which is the start of an array of " << this->component_ptrs[i][0] << " ints, namely: " << flush;
		for (int j = 1; j <= this->component_ptrs[i][0]; j++) {
			cout << this->component_ptrs[i][j] << " " << flush;
		}
		cout << endl;
	}
	cout << endl;
}
