#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {
		my_string = "";
	}

	ReversibleString (const string& s) {
		my_string = s;
	}

	void Reverse() {
		char tmp;
		int size = my_string.size();
		for (int i = 0; i < size/2; ++i) {
			tmp = my_string[i];
			my_string[i] = my_string[size - 1 - i];
			my_string[size - 1 - i] = tmp;
		}
	}

	string ToString() const {
		return my_string;
	}

private:
	string my_string;




};

int main() {

	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}

