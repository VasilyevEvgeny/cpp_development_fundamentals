// https://www.coursera.org/learn/c-plus-plus-white/programming/4X4vH/spisok-studientov

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string First_Name;
	string Last_Name;
	int Day_Of_Birth;
	int Month_Of_Birth;
	int Year_Of_Birth;
};

int main() {

	int N;
	cin >> N;

	vector<Student> students(N);


	for (int i = 0; i < N; ++i) {
		cin >> students[i].First_Name >> students[i].Last_Name >>
			students[i].Day_Of_Birth >> students[i].Month_Of_Birth >> students[i].Year_Of_Birth;
	}

	int M;
	cin >> M;

	int k;
	string command;
	for (int i = 0; i < M; ++i) {
		cin >> command;
		cin >> k;
		k--;
		if (command == "name" && k >=0 && k < N) {
			cout << students[k].First_Name << " " << students[k].Last_Name << endl;
		} else if (command == "date" && k >=0 && k < N) {
			cout << students[k].Day_Of_Birth << "." << students[k].Month_Of_Birth << "." << students[k].Year_Of_Birth << endl;
		} else
			cout << "bad request" <<endl;
	}

	return 0;
}

