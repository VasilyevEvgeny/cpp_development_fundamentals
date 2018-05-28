///*
// * quiz_search_algorithms.cpp
// *
// *  Created on: May 16, 2018
// *      Author: evgeny
// */
//
//
//#include <iostream>
//#include <set>
//
//using namespace std;
//
//int main() {
//
//	set<string> s = { "1first", "2second", "3third" };
//	auto range = s.equal_range("2second");
//
//	{
//		bool v1 = range.first == next(range.second);
//		cout <<  v1 << endl;
//	}
//	{
//		bool v2 = next(range.first) == prev(range.second);
//		cout <<  v2 << endl;
//	}
//	{
//		bool v3 = prev(range.first) == range.second;
//		cout <<  v3 << endl;
//	}
//	{
//		bool v4 = prev(range.first) == next(range.second);
//		cout << v4 << endl;
//	}
//	{
//	+
//		bool v5 = range.first == prev(range.second);
//		cout << v5 << endl;
//	}
//	{
//	+
//		bool v6 = range.first == range.second;
//		cout << v6 << endl;
//	}
//	{
//	+
//		bool v7 = next(range.first) == range.second;
//		cout << v7 << endl;
//	}
//	return 0;
//}
//
