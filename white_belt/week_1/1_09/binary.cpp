#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	vector<int> vect;

	cin >> N;

	if (N == 0)
		cout << 0;
	else if (N == 1)
		cout << 1;
	else {
		while (N >= 2) {
			vect.push_back(N % 2);
			N /= 2;
		}
		vect.push_back(1);

		for (int i = vect.size()-1; i >= 0; --i)
			cout << vect[i];

	}




	return 0;
}

