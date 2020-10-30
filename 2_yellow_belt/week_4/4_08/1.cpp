/*
 * main.cpp
 *
 *  Created on: May 14, 2018
 *      Author: evgeny
 */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool f(int x) {
	return x > 2.5;
}

void PrintSet(const set<int>& s) {
	for (const auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
}

void PrintVector(const vector<int>& v) {
	for (const auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {

	set<int> s = { 1, 4, 3, 5, 2 };
	vector<int> v;
//	{
// 	++++++++++++++++++++++++++++++++++++++++++++++++
//		v.assign(begin(s), end(s));
//		sort(begin(v), end(v),
//			 [](int lhs, int rhs) { return f(lhs) > f(rhs); });
//		auto it = partition_point(begin(v), end(v), f);
//		v.erase(begin(v), it);
//	}
//	{
//	++++++++++++++++++++++++++++++++++++++++++++++++
//		v.assign(begin(s), end(s));
//		auto it = partition(begin(v), end(v), f);
//		v.erase(begin(v), it);
//
//	}
//	{
//  ------------------------------------------------
//	remove_copy_if(begin(s), end(s), back_inserter(v),
//    [](int x) { return !f(x); });
//	}
//	{
//  ------------------------------------------------
//	copy_if(begin(s), end(s), back_inserter(v), f);
//
//	}
//	{
//  ------------------------------------------------
//		v.assign(begin(s), end(s));
//		auto it = partition(begin(v), end(v), f);
//		v.erase(it, end(v));
//	}
//	{
//  ++++++++++++++++++++++++++++++++++++++++++++++++
//		remove_copy_if(begin(s), end(s), back_inserter(v), f);
//	}
//	{
//	++++++++++++++++++++++++++++++++++++++++++++++++
//		copy_if(begin(s), end(s), back_inserter(v),
//		        [](int x) { return !f(x); });
//	}
//	{
//  ------------------------------------------------
//		v.assign(begin(s), end(s));
//		auto it = remove_if(begin(v), end(v),
//		                    [](int x) { return !f(x); });
//		v.erase(it, end(v));
//	}
//	{
//	++++++++++++++++++++++++++++++++++++++++++++++++
//		v.assign(begin(s), end(s));
//		auto it = remove_if(begin(v), end(v), f);
//		v.erase(it, end(v));
//	}
//	{
//	------------------------------------------------
//		vector<int> garbage;
//		partition_copy(
//		    begin(s), end(s),
//		    back_inserter(v), back_inserter(garbage), f);
//	}
//	{
//	------------------------------------------------
//		auto it = partition(begin(s), end(s), f);
//		copy(it, end(s), back_inserter(v));
//	}
//	{
//	------------------------------------------------
//		auto it = remove_if(begin(s), end(s),
//							[](int x) { return !f(x); });
//		copy(it, end(s), back_inserter(v));
//	}
//	{
//	++++++++++++++++++++++++++++++++++++++++++++++++
//		vector<int> garbage;
//		partition_copy(
//		    begin(s), end(s),
//		    back_inserter(garbage), back_inserter(v), f);

//	}
//	{
//	-------------------------------------------------
//		v.assign(begin(s), end(s));
//		sort(begin(v), end(v),
//		     [](int lhs, int rhs) { return f(lhs) > f(rhs); });
//		auto it = partition_point(begin(v), end(v), f);
//		v.erase(it, end(v));

//	}


	PrintSet(s);
	PrintVector(v);

	return 0;
}



