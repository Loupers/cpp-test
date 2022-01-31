//
// Created by pyrrhos on 31.01.22.
//

#ifndef TEST_FINAL_JOIN_H
#define TEST_FINAL_JOIN_H

#include "row.h"
#include <algorithm>

class join {
public:
	explicit join(std::ostream& of) : of_(of) {};
	void join_files(const vecrow& file1, const vecrow& file2);
private:
	vecstr get_all_keys(const row& r) const;
	bool are_matching_rows(const row& rowA, const row& rowB, const vecstr& matching_keys);
	vecstr merge_keys(const row& rowA, const row& rowB) const;
	void print_header(const vecstr keys);
	void print_row(const row& rowA, const row& rowB, const vecstr keys);
	vecstr find_matching_keys(const row& rowA, const row& rowB) const;

	std::ostream& of_;
};


#endif //TEST_FINAL_JOIN_H