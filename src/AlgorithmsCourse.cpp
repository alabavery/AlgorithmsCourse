//============================================================================
// Name        : AlgorithmsCourse.cpp
// Author      : Al
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// http://www.icce.rug.nl/documents/cplusplus/cplusplus09.html
// http://stackoverflow.com/questions/15604411/memory-allocation-deallocation
// #include "UnionFind/FirstImplementation.h"
#include "UnionFind/QuickFind.h"
#include "UnionFind/QuickUnion.h"

#include <iostream>
using namespace std;




int main() {

	//QuickUnion uf = QuickUnion();
	QuickFind uf = QuickFind();

	uf.init("src/UnionFind/stdinput.txt");
	cout << uf.test_connection(0, 2);
	return 0;
}
