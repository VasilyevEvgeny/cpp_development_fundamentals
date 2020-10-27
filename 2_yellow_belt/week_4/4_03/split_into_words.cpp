
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> words;
	auto it_start = begin(s);
	auto it_end = begin(s);
	auto it_end_new = begin(s);
	while (it_end_new != end(s)) {
		it_end_new = find_if(it_end, end(s), [](char symbol){
			return symbol == ' ';
		});

		it_start = it_end;
		words.push_back({it_start, it_end_new});

		if (it_end_new != end(s)) it_end = ++it_end_new;
	}

	return words;

}

int main() {
	string s = "ABC ps Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
	if (it != begin(words)) {
	  cout << "/";
	}
	cout << *it;
	}
	cout << endl;
}
