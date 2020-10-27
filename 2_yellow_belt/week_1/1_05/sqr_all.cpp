/*
 * sqr_all.cpp
 *
 *  Created on: May 7, 2018
 *      Author: evgeny
 */

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

// Предварительное объявление шаблонных функций

/*template <typename T> T Sqr(T x);
template<typename T> vector<T> operator* (const vector<T>& v1, const vector<T>& v2);
template<typename T1, typename T2> pair<T1,T2> operator* (const pair<T1,T2>& p1, const pair<T1,T2>& p2);
template<typename T1, typename T2, typename T3> map<T1,pair<T2,T3>> operator* (const map<T1,pair<T2,T3>>& m1, const map<T1,pair<T2,T3>>& m2);


template<typename T>
vector<T> operator* (const vector<T>& v1, const vector<T>& v2){
	vector<T> res(v1.size());
	for (size_t i = 0; i < v1.size(); ++i) {
		res[i] = v1[i] * v1[i];
	}
	return res;
}

template<typename T1, typename T2>
pair<T1,T2> operator* (const pair<T1,T2>& p1, const pair<T1,T2>& p2) {
	return {p1.first * p1.first, p1.second * p1.second};
}

template<typename T1, typename T2, typename T3>
map<T1,pair<T2,T3>> operator* (const map<T1,pair<T2,T3>>& m1, const map<T1,pair<T2,T3>>& m2) {
	map<T1,pair<T2,T3>> res;
	for (const auto& item : m1) {
		res[item.first] = item.second * item.second;
	}
	return res;
}

// Объявляем шаблонные функции
template <typename T>
T Sqr(T x) {
	return x * x;
}*/

template<typename T> vector<T> Sqr(const vector<T>& v);
template<typename T1, typename T2, typename T3> map<T1,pair<T2,T3>> Sqr(const map<T1,pair<T2,T3>>& m);
template<typename T1, typename T2> map<T1,T2> Sqr(const map<T1,T2>& m);
template<typename T1, typename T2> pair<T1,T2> Sqr(const pair<T1,T2>& p);
template<typename T1, typename T2> map<T1,vector<T2>> Sqr(const map<T1,vector<T2>>& m);
template<typename T> vector<T> operator* (const vector<T>& v1, const vector<T>& v2);
template<typename T> T Sqr(const T& x);

/*template<typename T>
vector<T> operator* (const vector<T>& v1, const vector<T>& v2) {
	vector<T> res(v1.size());
	for (size_t i = 0; i < v1.size(); ++i) {
		res[i] = v1[i] * v1[i];
	}
	return res;
}*/

template<typename T1, typename T2>
map<T1,vector<T2>> Sqr(const map<T1,vector<T2>>& m) {
	map<T1,vector<T2>> res;
	for (const auto& item : m) {
		vector<T2> tmp(item.second.size());
		for (size_t i = 0; i < item.second.size(); ++i) {
			tmp[i] = item.second[i] * item.second[i];
		}
		res[item.first] = tmp;
	}
	return res;
}

template<typename T>
vector<T> Sqr(const vector<T>& v) {
	vector<T> res(v.size());
	for (size_t i = 0; i < v.size(); ++i)
		res[i] = Sqr(v[i]);
	return res;
}

template<typename T1, typename T2, typename T3>
map<T1,pair<T2,T3>> Sqr(const map<T1,pair<T2,T3>>& m) {
	map<T1,pair<T2,T3>> res;
	for (const auto& item : m)
		res[item.first] = {item.second.first * item.second.first, item.second.second * item.second.second};
	return res;
}

template<typename T1, typename T2>
map<T1,T2> Sqr(const map<T1,T2>& m) {
	map<T1,T2> res;
	for (const auto& item : m)
		res[item.first] = item.second * item.second;
	return res;
}

template<typename T1, typename T2>
pair<T1,T2> Sqr(const pair<T1,T2>& p) {
	return {p.first * p.first, p.second * p.second};
}





template<typename T> T Sqr(const T& x) {
	return x * x;
}



/*template <typename Collection>
string Join(const Collection& c, char d) {
  stringstream ss;
  bool first = true;
  for (const auto& i : c) {
    if (!first) {
      ss << d;
    }
    first = false;
    ss << i;
  }
  return ss.str();
}

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p) {
  return out << '(' << p.first << ',' << p.second << ')';
}

template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi) {
  return out << '[' << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m) {
  return out << '{' << Join(m, ',') << '}';
}*/


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
	  {"7", {4.7, 3}}
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
