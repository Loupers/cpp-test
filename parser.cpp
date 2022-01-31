//
// Created by pyrrhos on 31.01.22.
//

#include "parser.h"

vecrow parser::parse(std::istream &in) const{
	std::string line;
	getline(in, line);
	vecstr keys = parse_line(line);
	vecrow rows;
	while (getline(in, line)) {
		vecstr values = parse_line(line);
		row r;
		for (size_t i = 0; i < keys.size(); ++i) {
			r.cells[keys[i]] = values[i];
		}
		rows.push_back(r);
	}
	return rows;
}

vecstr parser::parse_line(std::string& line) const {
	char separator = ',';
	vecstr res;
	std::string current = "";
	for (auto&& i = line.begin(); i != line.end(); i++) {
		if (*i == separator) {
			res.push_back(current);
			current = "";
		} else {
			current.push_back(*i);
		}
	}
	res.push_back(current);
	return res;
}