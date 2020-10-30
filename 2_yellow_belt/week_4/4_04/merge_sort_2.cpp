// https://www.coursera.org/learn/c-plus-plus-yellow/programming/wlbIg/sortirovka-sliianiiem

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//template<typename T>
//void PrintVector(const vector<T>& v ) {
//	for (const auto& e : v)
//		cout << e << " ";
//	cout << endl;
//}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	size_t size = distance(range_begin, range_end);
	size_t half = size / 2;

	if (size < 2)
		return;

	MergeSort(range_begin, range_begin + half);
	MergeSort(range_begin + half, range_end);

	vector<typename RandomIt::value_type> elements;
	merge(range_begin, range_begin + half, range_begin + half, range_end, back_inserter(elements),
			[](const auto& lhs, const auto& rhs){
				return lhs < rhs;
	});

	for (auto it = range_begin; it != range_end; ++it)
		*it = elements[it-range_begin];
}

//int main() {
//	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
//	MergeSort(begin(v), end(v));
//	for (int x : v) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
