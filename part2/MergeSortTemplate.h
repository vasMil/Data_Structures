#pragma once
#include <stdio.h>
#include <vector>
class node;
//https://www.tutorialspoint.com/Why-can-Cplusplus-templates-only-be-implemented-in-the-header-file
//Solution to that may provide the keyword export
//diabase: https://vector-of-bool.github.io/2019/03/31/modules-2.html

template <typename funcType>
void Merge(std::vector<node>& inp, std::vector<node> &left, std::vector<node> &right, funcType(node::* func)()) {
	unsigned int l = 0, r = 0;
	std::vector<node> sorted;

	while (l < left.size() && r < right.size()) {
		if ((left[l].*func)() < (right[r].*func)()) {
			sorted.push_back(left[l]);
			l++;
		}
		else {
			sorted.push_back(right[r]);
			r++;
		}
	}

	if (l < left.size()) {
		while (l < left.size()) {
			sorted.push_back(left[l]);
			l++;
		}
	}
	if (r < right.size()) {
		while (r < right.size()) {
			sorted.push_back(right[r]);
			r++;
		}
	}
	inp = sorted;
}


template <typename funcType>
void SortMaybe(std::vector<node> &inp, funcType(node::* func)()) {
	unsigned int size = inp.size();
	std::vector<node>::const_iterator  it1 = inp.begin(), it2 = inp.begin() + (int)floor(size / 2), it3 = inp.end();
	std::vector<node> left(it1, it2), right(it2, it3);

	if (left.size() > 1) {
		SortMaybe(left, func);
	}
	if (right.size() > 1) {
		SortMaybe(right, func);
	}
	Merge(inp, left, right, func);
}

//I NEED COMMENTS FOR THE CURRENT IMPLEMENTENTION, I HOPE I DON'T SCREW UP ANY CODING GUIDELINES