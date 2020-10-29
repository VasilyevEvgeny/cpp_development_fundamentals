// https://www.coursera.org/learn/c-plus-plus-white/programming/WRbZE/sinonimy

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {

	int Q;
	cin >> Q;

	map<string,set<string>> dict;

	string command;
	for (int q = 0; q < Q; ++q) {
		cin >> command;
		if (command == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			dict[word1].insert(word2);
			dict[word2].insert(word1);
		}
		else if (command == "COUNT") {
			string word;
			cin >> word;
			cout << dict[word].size() << endl;
		}
		else if (command == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			if (dict[word1].count(word2) > 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}
