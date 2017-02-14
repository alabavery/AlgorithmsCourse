/*
 * FirstImplementation.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: alavery
 *
 *
 *  FirstImplementation starts with int * pointing to arrays just containing i for
 *  each i in 0 < i < N.  Union iterates through each i's array and combines, then
 *  replaces the pointers for all i's that were a part of either component involved
 *  in the union with a pointer to the new array.
 *
 *  Find just sees if the pointers in p and q spots point to the same address.
 */
#include <vector>
#include <stdlib.h>
#include "FirstImplementation.h"
#include <iostream>
#include <fstream>
using namespace std;


void FirstImplementation::init(string stdinput_file_path) {
	this->default_init(stdinput_file_path);
}


void FirstImplementation::init(int N) {
	this->default_init(N);
}


void FirstImplementation::initialize_id()
{
	for (int i = 0; i < N; i++) {
		int* this_component = new int[2];
		this_component[0] = 1;
		this_component[1] = i;
		this->component_ptrs.push_back(this_component);
	}
}


void FirstImplementation::unionize(int p, int q) {

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


bool FirstImplementation::test_connection(int p, int q) {
	if (this->component_ptrs[p] == this->component_ptrs[q]) return true;
	else return false;
}


void FirstImplementation::print_components() {
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
