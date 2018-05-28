#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	/*ifstream input("input.txt");
	string line;
	while (getline(input, line)) {
		cout << line << endl;
	}*/

	ifstream input2("input.txt");
	string line2;
	vector<string> lines;
	while (getline(input2, line2)) {
		lines.push_back(line2);
	}

	ofstream output("output.txt");
	for (const auto& current_line : lines) {
		output << current_line << endl;
	}

	return 0;
}
