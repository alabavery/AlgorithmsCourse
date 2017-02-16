/*
 * MinimumSpanningTrees.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: alavery
 */

#include "MinimumSpanningTrees.h"


GenericMST::GenericMST(int N, string displaytreetxtpath) {
	this->N = N;
	this->prime_node = 0;
	this->uf = WeightedQuickUnion();
	this->uf.init(this->N, displaytreetxtpath);

	int counter = 0;
	int p = 1;
	while (p > 0) {
		this->uf.union_and_print_wrapper(p, this->prime_node);
		p = this->find_next_node();
		counter++;
	}
	this->uf.print_to_file();
}


bool GenericMST::check_if_done() {
	/*eventually want to change this method to take advantage of uf's
	 * tree_sizes array... problem now is that only wtdquickunion uses
	 * tree_sizes array, other UF classes don't have it
	 */
	for (int i = 0; i < this->N; i++) {
		if (uf.get_root(i) != this->prime_node) {
			return false;
		}
	}
	return true;
}


int GenericMST::find_next_node() {
	for (int i = 0; i < this->N; i++) {
		if (this->uf.get_root(i) != this->prime_node) {
			return i; // first we wont worry about minimum weighting
		}
	}
	return -1;
}
