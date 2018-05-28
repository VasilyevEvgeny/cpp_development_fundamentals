/*
 * part_of_vector.cpp
 *
 *  Created on: May 13, 2018
 *      Author: evgeny
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto it = begin(numbers);
	for (;it != end(numbers); ++it) {
		if (*it < 0)
			break;
		//cout << *it << endl;
	}
	while (it > begin(numbers)) {
		--it;
		cout << *it << " ";
	}
	cout << endl;

}

/*int main() {
	PrintVectorPart({6, 1, 8, -5, 4});
	PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	PrintVectorPart({6, 1, 8, 5, 4});

	return 0;
}*/


