#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;

	cin >> str;

	int n = 0, idx;
	for (int i = 0; i < str.size(); ++i){
		if (str[i] == 'f')
			++n;
		if (n == 2) {
			idx = i;
			break;
		}


	}

	if (n == 0)
		cout << -2 << endl;
	else if (n == 1)
		cout << -1 << endl;
	else
		cout << idx << endl;

	return 0;
}
