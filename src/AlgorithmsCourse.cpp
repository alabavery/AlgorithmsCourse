//============================================================================
// Name        : AlgorithmsCourse.cpp
// Author      : Al
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// http://www.icce.rug.nl/documents/cplusplus/cplusplus09.html
// http://stackoverflow.com/questions/15604411/memory-allocation-deallocation
#include "UnionFind/FirstImplementation.h"
#include "UnionFind/QuickFind.h"
#include "UnionFind/QuickUnion.h"
#include "UnionFind/WeightedQuickUnion.h"

#include <iostream>
using namespace std;



int main() {

	//QuickUnion uf = QuickUnion();
	//QuickFind uf = QuickFind();
	//FirstImplementation uf = FirstImplementation();
	WeightedQuickUnion uf = WeightedQuickUnion();

	uf.init("src/UnionFind/stdinput.txt");
    cout << uf.get_root(2);
	return 0;
}
