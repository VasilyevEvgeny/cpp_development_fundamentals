#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

	int N = 0, M = 0;

	ifstream input("input.txt");

	input >> N;
	input.ignore(1);
	input >> M;

	int val = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			input >> val;
			input.ignore(1);
			cout << setw(10) << val;
			if (j != M-1)
				cout << " ";
		}
		if (i != N-1)
			cout << endl;
	}

	return 0;
}

