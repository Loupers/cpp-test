//
// Created by pyrrhos on 31.01.22.
//

#ifndef TEST_FINAL_PARSER_H
#define TEST_FINAL_PARSER_H

#include <iostream>
#include "row.h"

class parser {
public:
	vecrow parse(std::istream& in) const;
private:
	vecstr parse_line(std::string& line) const;
};


#endif //TEST_FINAL_PARSER_H