// https://www.coursera.org/learn/c-plus-plus-yellow/programming/wlbIg/sortirovka-sliianiiem

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void PrintVector(const vector<T>& v ) {
	for (const auto& e : v)
		cout << e << " ";
	cout << endl;
}


template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	size_t size = distance(range_begin, range_end);
	size_t third = size / 3;

	if (size < 3)
		return;

	MergeSort(range_begin, range_begin + third);
	MergeSort(range_begin + third, range_begin + 2 * third);
	MergeSort(range_begin + 2 * third, range_end);



	vector<typename RandomIt::value_type> elements_tmp;
	merge(range_begin, range_begin + third, range_begin + third, range_begin + 2 * third, back_inserter(elements_tmp),
			[](const auto& lhs, const auto& rhs){return lhs < rhs;});

	vector<typename RandomIt::value_type> elements;
	merge(begin(elements_tmp), end(elements_tmp), range_begin + 2 * third, range_end, back_inserter(elements),
			[](const auto& lhs, const auto& rhs){return lhs < rhs;});

	for (auto it = range_begin; it != range_end; ++it)
		*it = elements[it-range_begin];
}

/*
int main() {
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 3};
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
*/