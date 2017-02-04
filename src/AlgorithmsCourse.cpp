//============================================================================
// Name        : AlgorithmsCourse.cpp
// Author      : Al
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// http://www.icce.rug.nl/documents/cplusplus/cplusplus09.html
// http://stackoverflow.com/questions/15604411/memory-allocation-deallocation
#include <iostream>
#include <fstream>
#include <vector>
#include "UnionFind.h"
using namespace std;


int main() {

	UnionFind uf = UnionFind("stdinput.txt");
	uf.print_components();

	return 0;
}
