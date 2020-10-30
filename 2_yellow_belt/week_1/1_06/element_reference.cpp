// https://www.coursera.org/learn/c-plus-plus-yellow/programming/ju9bq/ssylka-na-eliemient

#include <iostream>
#include <map>
#include <string>
#include <exception>

using namespace std;

template<typename K, typename V>
V& GetRefStrict(map<K,V>& m, K k) {
	try {
		return m.at(k);
	} catch (...) {
		throw runtime_error("");
	}

}

/*int main() {

	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	cout << item << endl;
	item = "newvalue";
	cout << m[1] << endl; // выведет newvalue

	return 0;
}*/

