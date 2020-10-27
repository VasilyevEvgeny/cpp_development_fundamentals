/*
 * realizations_of_functions.cpp
 *
 *  Created on: May 12, 2018
 *      Author: evgeny
 */

#include "sum_reverse_sort.h"
#include <algorithm>

using namespace std;

int Sum(int x, int y) {
	return x + y;
}

string Reverse(string s) {
	size_t half_size = s.size() / 2;
	for (size_t i = 0; i < half_size; ++i) {
		char tmp = s[i];
		s[i] = s[s.size()-1-i];
		s[s.size()-1-i] = tmp;
	}
	return s;
}

void Sort(vector<int>& nums) {
	sort(begin(nums), end(nums));
	/*for (size_t i = 0; i < nums.size(); ++i) {
		for (size_t j = 0; j < i; ++j) {
			if (nums[i] < nums[j]) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}*/
}

