/*
 * blocks_mass.cpp
 *
 *  Created on: May 2, 2018
 *      Author: evgeny
 */

#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

int main() {

	//cout << numeric_limits<size_t>::min() << " " << numeric_limits<size_t>::max() << endl;
	//cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;

	size_t N = 0, R = 0;
	cin >> N >> R;

	uint64_t mass = 0;
	size_t a = 0, b = 0, c = 0;
	for (size_t i = 0; i < N; ++i) {
		cin >> a >> b >> c;
		mass += (a * b * c) * R;
	}

	cout << mass << endl;


	return 0;
}


