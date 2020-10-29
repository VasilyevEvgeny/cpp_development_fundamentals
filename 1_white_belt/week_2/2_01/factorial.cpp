// https://www.coursera.org/learn/c-plus-plus-white/programming/SqolV/faktorial

//#include <iostream>

//using namespace std;

int Factorial(int n) {
	if (n <= 1)
		return 1;
	else {
		int s = 1;
		for (int i = 2; i <= n; ++i)
			s *= i;
		return s;
	}
}

/*int main() {

	cout << Factorial(6) << endl;


	return 0;
}*/


