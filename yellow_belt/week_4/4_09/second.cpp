/*
 * second.cpp
 *
 *  Created on: May 16, 2018
 *      Author: evgeny
 */



#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindSegment(
    RandomIt range_begin, RandomIt range_end, int left, int right) {

//	+
//	return {upper_bound(range_begin, range_end, left - 1),
//	        lower_bound(range_begin, range_end, right + 1)};

//  -
//	return {upper_bound(range_begin, range_end, left),
//	        upper_bound(range_begin, range_end, right)};

//	-
//	return {upper_bound(range_begin, range_end, left),
//	        upper_bound(range_begin, range_end, right)};

//	-
//	return {upper_bound(range_begin, range_end, left),
//	        lower_bound(range_begin, range_end, right)};

//	-
//	return {next(lower_bound(range_begin, range_end, left - 1)),
//	        prev(upper_bound(range_begin, range_end, right + 1))};

//	+
//	return {lower_bound(range_begin, range_end, left),
//	        upper_bound(range_begin, range_end, right)};
}

int main() {

	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto p = FindSegment(begin(v), end(v), 3, 5);

	for (auto it = p.first; it != p.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
