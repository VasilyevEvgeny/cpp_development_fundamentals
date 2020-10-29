// https://www.coursera.org/learn/c-plus-plus-white/programming/zqw0h/sortirovka-biez-uchiota-rieghistra

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<string> v(N);

	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(begin(v), end(v), [](string s1, string s2) {
		for (unsigned int i = 0; i < s1.size(); ++i)
			s1[i] = tolower(s1[i]);
		for (unsigned int i = 0; i < s2.size(); ++i)
			s2[i] = tolower(s2[i]);
		return (s1 < s2);
	});

	for (const auto& e : v)
		cout << e << " ";
	cout << endl;

	return 0;
}

