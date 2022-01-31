//
// Created by pyrrhos on 31.01.22.
//

#include "join.h"
#include "iostream"
#include <string>

void join::join_files(const std::vector<row> &file1, const std::vector<row> &file2) {
	const vecstr matching_keys = find_matching_keys(file1.at(0), file2.at(0));

	vecstr output_keys = merge_keys(file1.at(0), file2.at(0));
	std::sort(output_keys.begin(), output_keys.end());

	print_header(output_keys);

	for (auto&& it = file1.cbegin(); it != file1.cend(); ++it) {
		for (auto&& it2 = file2.cbegin(); it2 != file2.cend(); ++it2) {
			if (are_matching_rows(*it, *it2, matching_keys)) {
				print_row(*it, *it2, output_keys);
			}
		}
	}
}



bool join::are_matching_rows(const row &rowA, const row &rowB, const vecstr &matching_keys){
	for (auto&& it = matching_keys.cbegin(); it != matching_keys.cend(); ++it) {
		if (rowA.cells.at(*it) != rowB.cells.at(*it)) {
			return false;
		}
	}
	return true;
}

vecstr join::get_all_keys(const row& r) const {
	vecstr keys;
	for (auto&& it = r.cells.cbegin(); it != r.cells.cend(); ++it) {
		keys.push_back(it->first);
	}
	return keys;
}

vecstr join::merge_keys(const row &rowA, const row &rowB) const {
	vecstr keys = get_all_keys(rowA);
	vecstr other_keys = get_all_keys(rowB);
	for (auto&& it = other_keys.cbegin(); it != other_keys.cend(); ++it) {
		if (find(keys.cbegin(), keys.cend(), *it) == keys.cend()) {
			keys.push_back(*it);
		}
	}
	return keys;
}



vecstr join::find_matching_keys(const row &rowA, const row &rowB) const {
	vecstr matching;
	vecstr file1_keys = get_all_keys(rowA);
	vecstr file2_keys = get_all_keys(rowB);

	for (auto&& it = file2_keys.cbegin(); it != file2_keys.cend(); ++it) {
		auto&& match = std::find(file1_keys.cbegin(), file1_keys.cend(), *it);
		if (match != file1_keys.cend()) {
			matching.push_back(*match);
		}
	}
	return matching;
}

void join::print_row(const row &rowA, const row &rowB, const vecstr keys) {
	for (auto&& it = keys.cbegin(); it != keys.cend(); ++it) {
		if (rowA.cells.count(*it)) {
			of_ << rowA.cells.at(*it);
		} else {
			of_ << rowB.cells.at(*it);
		}

		if (it != keys.cend() - 1) {
			of_ << ",";
		}
	}
	of_ << std::endl;
}

void join::print_header(const vecstr keys) {
	for (auto&& it = keys.cbegin(); it != keys.cend(); ++it) {
		of_ << *it;
		if (it != keys.cend() - 1) {
			of_ << ",";
		}
	}
	of_ << std::endl;
}