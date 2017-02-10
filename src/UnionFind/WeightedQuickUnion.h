
#include "QuickUnion.h"

#ifndef UNIONFIND_WEIGHTEDQUICKUNION_H_
#define UNIONFIND_WEIGHTEDQUICKUNION_H_


class WeightedQuickUnion : public QuickUnion {
private:
	void unionize(int p, int q);
	int get_tree_size(int p);
};


#endif /* UNIONFIND_WEIGHTEDQUICKUNION_H_ */
