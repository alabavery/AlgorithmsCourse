
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
	int p_tree_size = this->get_tree_size(p);
	int q_tree_size = this->get_tree_size(q);
	if (p_tree_size > q_tree_size) {
		int temp_p = p;
		p = q;
		q = temp_p;
	}
	int p_root = this->get_root(p);
	this->id[p_root] = this->get_root(q);
	this->tree_sizes[this->get_root(q)] = p_tree_size + q_tree_size;
}


int WeightedQuickUnion::get_tree_size(int p)
{
	int p_root = this->get_root(p);
	int tree_size = this->tree_sizes[p_root]; // error coming from this line
	return tree_size;
}

