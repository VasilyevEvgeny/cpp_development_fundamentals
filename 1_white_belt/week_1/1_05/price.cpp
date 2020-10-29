// https://www.coursera.org/learn/c-plus-plus-white/programming/baBml/raschiot-stoimosti-tovara

#include <iostream>

using namespace std;

int main() {

	double N, A, B, X, Y;

	cin >> N >> A >> B >> X >> Y;

	if (N <= A)
		cout << N << endl;
	else if (N > A && N <= B)
		cout << N - N * 0.01 * X << endl;
	else
		cout << N - N * 0.01 * Y << endl;

	return 0;
}

