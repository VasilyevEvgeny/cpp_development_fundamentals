#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {

	int N;
	cin >> N;

	vector<int> v(N);

	int n;
	for (int i =0; i < N; ++i) {
		cin >> n;
		v[i] = n;
	}

	sort(begin(v), end(v), [](int i, int j) { return (abs(i)<abs(j)); });

	for (const auto& e : v)
		cout << e << " ";
	cout << endl;

	return 0;
}
