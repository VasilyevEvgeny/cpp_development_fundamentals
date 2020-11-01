// https://www.coursera.org/learn/c-plus-plus-yellow/programming/YQJs1/vsio-v-kvadrat

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

// Предварительные объявления шаблонных функций

template<typename T> T Sqr(T x);
template<typename T> vector<T> Sqr(const vector<T>& v);
template<typename T1, typename T2> pair<T1,T2> Sqr(const pair<T1,T2>& p);
template<typename T1, typename T2> map<T1,T2> Sqr(const map<T1,T2>& m);


// Определения шаблонных функций

template <typename T>
T Sqr(T x) {
    return x * x;
}

template<typename T>
vector<T> Sqr(const vector<T>& v) {
    vector<T> res(v.size());
    for (size_t i = 0; i < v.size(); ++i)
        res[i] = Sqr(v[i]);
    return res;
}

template<typename T1, typename T2>
pair<T1,T2> Sqr(const pair<T1,T2>& p) {
    return {Sqr(p.first), Sqr(p.second)};
}

template<typename T1, typename T2>
map<T1,T2> Sqr(const map<T1,T2>& m) {
    map<T1,T2> res;
    for (const auto& item : m)
        res[item.first] = Sqr(item.second);
    return res;
}


int main() {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<string, pair<double, int>> map_of_pairs = {
	  {"4", {2.0, 2}},
	  {"7", {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

	cout << Sqr(2) << endl;

	map<int, vector<double>> map_of_vectors = {
			{1 , {3.5, 5.6, 7.8}},
			{4 , {3.5, 5.6, 7.8}}
	};
	cout << "map of vectors:" << endl;
	for (const auto& x : Sqr(map_of_vectors)) {
		cout << x.first;
		for (size_t i = 0; i < x.second.size(); ++i) {
			cout << " " << x.second[i];
		}
		cout << endl;
	}
}

