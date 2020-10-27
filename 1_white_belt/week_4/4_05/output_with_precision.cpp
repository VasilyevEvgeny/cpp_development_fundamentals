#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double power(double val, int p) {
	for (int i = 0; i < p; ++i)
		val *= 10;

	return val;
}

int main() {

	ifstream input("input.txt");

	string line;
	int i = 0;
	while (getline(input, line)) {
		if (i != 0)
			cout << endl;
		double val = stod(line);
		cout << fixed << setprecision(3);
		cout << val;
		++i;
	}

	/*int prec = 3;
	double powered = power(1, prec);

	double val = 0.0;
	int i = 0;
	while(input) {
		input >> val;
		if (val != 0) {
			if (i != 0)
				cout << endl;
			cout << fixed << setprecision(prec);
			double val_multiplied = val * powered;
			double new_val =  val_multiplied - int(val_multiplied) >= 0.5 ? int(val_multiplied + 1) / powered : int(val_multiplied) / powered ;
			cout << new_val;
			val = 0.0;
		}
		++i;
	}*/

	return 0;
}

