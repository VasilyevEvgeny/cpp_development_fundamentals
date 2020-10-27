//#include <iostream>
//#include <string>

//using namespace std;


bool IsPalindrom(string str) {
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		if (str[i] != str[len-1-i])
			return false;
	}

	return true;

}

/*int main() {

	cout << IsPalindrom("aggergga") << endl;

	return 0;
}*/
