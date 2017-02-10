
#include "WeightedQuickUnion.h"
#include <fstream>
#include <iostream>
using namespace std;


void WeightedQuickUnion::init(string stdinput_file_path) {
	this->default_init(stdinput_file_path);
	this->tree_sizes = new int[this->N];
}


void WeightedQuickUnion::unionize(int p, int q)
{
	if (this->get_tree_size(p) > this->get_tree_size(q)) {
		int temp_p = p;
		p = q;
		q = temp_p;
	}

	int p_root = this->get_root(p);
	id[p_root] = this->get_root(q);
}


int WeightedQuickUnion::get_tree_size(int p)
{
	int p_root = this->get_root(p);
	int tree_size = 0;
	for (int i = 0; i < this->N; i++) {
		if (this->get_root(this->id[i]) == p_root) {
			tree_size++;
		}
	}
	return tree_size;
}

