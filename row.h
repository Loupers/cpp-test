//
// Created by pyrrhos on 31.01.22.
//

#ifndef TEST_FINAL_ROW_H
#define TEST_FINAL_ROW_H

#include <map>
#include <string>
#include <vector>

struct row {
	std::map<std::string, std::string> cells;
};

using vecstr = std::vector<std::string>;
using vecrow = std::vector<row>;

#endif //TEST_FINAL_ROW_H