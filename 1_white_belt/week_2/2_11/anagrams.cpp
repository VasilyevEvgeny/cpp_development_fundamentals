#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

void print_map(map<char,int> m) {
	for (const auto& item : m)
		cout << item.first << " " << item.second << endl;

}

map<char,int> BuildCharCounters (string str) {
	map<char,int> m;
	for (int i = 0; i < str.size(); ++i) {
		int n = 0;
		for (int j = 0; j < str.size(); ++j)
			if (str[j] == str[i])
				n++;

		m[str[i]] = n;

	}

	return m;

}

int main() {

	int N;
	cin >> N;

	vector<string> words_left(N), words_right(N);

	for (int i = 0; i < N; ++i) {
		cin >> words_left[i] >> words_right[i];

	}

	//for (int i = 0 ;i < N; ++i)
	//	cout << words_left[i] << " " << words_right[i] << endl;

	for (int n_word = 0; n_word < N; ++n_word) {
		map<char,int> map_left = BuildCharCounters(words_left[n_word]);
		map<char,int> map_right = BuildCharCounters(words_right[n_word]);
		if (map_left == map_right)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	//print_map(map_1);

	return 0;
}

