
#include "QuickUnion.h"

#ifndef UNIONFIND_WEIGHTEDQUICKUNION_H_
#define UNIONFIND_WEIGHTEDQUICKUNION_H_


class WeightedQuickUnion : public QuickUnion {
private:
	void unionize(int p, int q);
	int* tree_sizes; // array of N length, but only the nodes that are currently roots are up to date
public:
	void init(string stdinput_file_path);
};


#endif /* UNIONFIND_WEIGHTEDQUICKUNION_H_ */
