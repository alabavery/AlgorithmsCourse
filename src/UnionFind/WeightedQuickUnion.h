
#include "QuickUnion.h"

#ifndef UNIONFIND_WEIGHTEDQUICKUNION_H_
#define UNIONFIND_WEIGHTEDQUICKUNION_H_


class WeightedQuickUnion : public QuickUnion {
private:
	int* tree_sizes; // array of N length, but only the nodes that are currently roots are up to date
public:
	void init(string stdinput_file_path);
	void init(int N);
	void unionize(int p, int q);
};


#endif /* UNIONFIND_WEIGHTEDQUICKUNION_H_ */
