// https://www.coursera.org/learn/c-plus-plus-white/programming/ZajnT/otbor-palindromov

/*#include <iostream>
#include <string>
#include <vector>

using namespace std;*/

bool IsPalindrom(string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> v;
	for(auto s: words) {
		if (IsPalindrom(s) && s.size() >= minLength)
			v.push_back(s);
	}
	return v;
}

/*int main() {



	return 0;
}*/

