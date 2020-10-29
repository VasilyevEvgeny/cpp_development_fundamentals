// https://www.coursera.org/learn/c-plus-plus-white/programming/7rcDW/kolichiestvo-unikal-nykh-strok

#include <iostream>
#include <set>

using namespace std;

int main() {

	int N;
	cin >> N;

	set<string> strings;

	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		strings.insert(s);
	}

	cout << strings.size() << endl;

	return 0;
}

