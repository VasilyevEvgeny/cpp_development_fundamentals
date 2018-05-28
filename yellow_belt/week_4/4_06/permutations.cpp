/*
 * permutations.cpp
 *
 *  Created on: May 14, 2018
 *      Author: evgeny
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void PrintVector(const vector<int>& v) {
	for (const auto& e : v)
		cout << e << " ";
	cout << endl;
}



int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	iota(begin(v), end(v), 1);
	sort(begin(v), end(v), greater<>());

	do {
		PrintVector(v);
	} while(prev_permutation(v.begin(), v.end()));



	return 0;
}

