///*
// * arithmetic1.cpp
// *
// *  Created on: May 22, 2018
// *      Author: evgeny
// */
//
//#include <iostream>
//#include <deque>
//#include <string>
//
//using namespace std;
//
//void PrintArithm(deque<string> d) {
//	for (const auto& e : d)
//		cout << e;
//	cout << endl;
//
//}
//
//int main() {
//
//	int x;
//	cin >> x;
//	size_t N;
//	cin >> N;
//
//	deque<string> arithm;
//	arithm.push_back(to_string(x));
//
//	for (size_t i = 0; i < N; ++i) {
//		string operation;
//		cin >> operation;
//		int number;
//		cin >> number;
//
//		arithm.push_front("(");
//		arithm.push_back(") " + operation + " " + to_string(number) );
//	}
//
//	PrintArithm(arithm);
//
//
//	return 0;
//}
//
//
