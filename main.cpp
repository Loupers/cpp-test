#include <iostream>
#include <fstream>
#include "parser.h"
#include "join.h"



std::ifstream open_file(const std::string& name) {
	std::ifstream ifs;
	ifs.open(name);
	if (!ifs.good()) {
		std::cerr << "cannot open file " << name << std::endl;
		exit(0);
	}
	return ifs;
}

int main(int argc, char** argv) {
	std::vector<std::string> args(argv, argv + argc);
	if (args.size() < 4) {
		std::cerr << "not enough params" << std::endl;
		return 0;
	}

	parser p;
	std::ifstream fin = open_file(args[1]);
	std::vector<row> file1_rows = p.parse(fin);

	fin = open_file(args[2]);
	std::vector<row> file2_rows = p.parse(fin);

	std::ofstream of(args[3]);

	join joiner(of);
	joiner.join_files(file1_rows, file2_rows);
	return 0;
}