/*
 * StdInputReading.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: alavery
 */

#include "StdInputReading.h"


int read_N_from_stdinput(string file_path) {
	string sz_a_line;
	ifstream std_input_stream(file_path);

	if (std_input_stream.is_open()) {
		getline(std_input_stream, sz_a_line);
		int N = stoi(sz_a_line);
		std_input_stream.close();
		return N;
	}
	else {
		cout << "Couldn't open" << endl;
		return -1;
	}
}

typedef void (*unionFxn)(int,int,int*);
void iterate_unions_in_stdinput(int * id, unionFxn unionize, string file_path) {
	ifstream std_input_stream(file_path);
	string sz_a_line;

	if (std_input_stream.is_open()) {
		getline(std_input_stream, sz_a_line); // just N, ignore

		while ( getline (std_input_stream, sz_a_line) ) {
			int first_node = stoi(sz_a_line.substr(0,2));
			int second_node = stoi(sz_a_line.substr(2));
			unionize(first_node, second_node, id);
		}
		std_input_stream.close();

	} else {
		cout << "Couldn't open" << endl;
	}
}
