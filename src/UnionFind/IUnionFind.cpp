#include <fstream>
#include <iostream>
#include "IUnionFind.h"
using namespace std;


void IUnionFind::init(string stdinput_file_path) {
	this->assign_N_from_stdinput(stdinput_file_path);
	this->initialize_id();
	this->iterate_unions_in_stdinput(stdinput_file_path);
}


void IUnionFind::assign_N_from_stdinput(string file_path) {
	string sz_a_line;
	ifstream std_input_stream(file_path);

	if (std_input_stream.is_open()) {
		getline(std_input_stream, sz_a_line);
		this->N = stoi(sz_a_line);
		std_input_stream.close();
	}
	else {
		cout << "Couldn't open" << endl;
	}
}


void IUnionFind::default_initialize_id() {
	cout << "Called";
	this->id = new int[this->N];
	for (int i = 0; i < this->N; i++) {
		this->id[i] = i;
	}
}


void IUnionFind::iterate_unions_in_stdinput(string file_path) {
	ifstream std_input_stream(file_path);
	string sz_a_line;

	if (std_input_stream.is_open()) {
		getline(std_input_stream, sz_a_line); // just N, ignore

		while (getline (std_input_stream, sz_a_line) ) {
			int first_node = stoi(sz_a_line.substr(0,2));
			int second_node = stoi(sz_a_line.substr(2));
			this->unionize(first_node, second_node);
		}
		std_input_stream.close();

	} else {
		cout << "Couldn't open" << endl;
	}
}
