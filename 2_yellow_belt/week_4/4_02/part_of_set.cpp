// https://www.coursera.org/learn/c-plus-plus-yellow/programming/LSMnD/chast-mnozhiestva

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	auto res_it = find_if(begin(elements), end(elements),
		[border](const T& e) {
			return e > border;
		}
	);

	//cout << *res_it << endl;

	vector<T> res;
	for (auto it = res_it; it != end(elements); ++it) {
		res.push_back(*it);
	}

	return res;
}

int main() {
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;

	return 0;
}
