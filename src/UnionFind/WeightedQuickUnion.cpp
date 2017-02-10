
#include "WeightedQuickUnion.h"
#include <fstream>
#include <iostream>
using namespace std;


void WeightedQuickUnion::init(string stdinput_file_path) {
	this->assign_N_from_stdinput(stdinput_file_path);
	this->tree_sizes = new int[this->N];
	fill_n(this->tree_sizes, this->N, 1);
	this->initialize_id();
	this->iterate_unions_in_stdinput(stdinput_file_path);
}


void WeightedQuickUnion::unionize(int p, int q)
{
	int p_root = this->get_root(p);
	int q_root = this->get_root(q);
	if (p_root == q_root) {
		return;
	}
	int p_root_tree_size = this->tree_sizes[p_root];
	int q_root_tree_size = this->tree_sizes[q_root];
	if (p_root_tree_size > q_root_tree_size) {
		this->id[q_root] = p_root;
		this->tree_sizes[p_root] += q_root_tree_size;
	} else {
		this->id[p_root] = q_root;
		this->tree_sizes[q_root] += p_root_tree_size;
	}
}

