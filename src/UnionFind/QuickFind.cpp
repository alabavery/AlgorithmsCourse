
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "QuickFind.h"

using namespace std;

void QuickFind::init(string stdinput_file_path) {
	this->default_init(stdinput_file_path);
}


void QuickFind::unionize(int p, int q) {
	for (int i = 0; i < this->N; i++) {
		if (this->id[i] == p) {
			this->id[i] = id[q];
		}
	}
}


void QuickFind::initialize_id() {
	this->default_initialize_id();
}

bool QuickFind::test_connection(int p, int q) { // not working all the sudden.. false negatives
	return this->id[p] == this->id[q];
}
