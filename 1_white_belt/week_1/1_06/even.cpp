#include <iostream>

using namespace std;

int main() {

	int a, b;

	cin >> a >> b;

	int n = a;
	while (n <= b) {
		if (n % 2 == 0)
			cout << n << " ";
		++n;
	}

	return 0;
}

