#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double A, B, C;

	cin >> A >> B >> C;

	if (A == 0){
		if (B == 0){
			cout << "" << endl;
		}
		else {
			cout << -C/B << endl;
		}
	}
	else {
		double D_squared = B * B - 4.0 * A * C;
		if (D_squared < 0) {
			cout << "" << endl;
		}
		else if (D_squared == 0) {
			cout << -B / (2.0 * A) << endl;
		}
		else {
			cout << (-B + sqrt(D_squared)) / (2.0 * A) << " " << (-B - sqrt(D_squared)) / (2.0 * A) << endl;
		}
	}

	return 0;
}

