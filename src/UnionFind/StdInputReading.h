/*
 * StdInputReading.h
 *
 *  Created on: Feb 6, 2017
 *      Author: alavery
 */

#ifndef UNIONFIND_STDINPUTREADING_H_
#define UNIONFIND_STDINPUTREADING_H_


#include <fstream>
#include <iostream>
using namespace std;


int read_N_from_stdinput(string file_path);
void iterate_unions_in_stdinput(int * id, void (*unionize)(int p, int q, int * id), string file_path);



#endif /* UNIONFIND_STDINPUTREADING_H_ */
