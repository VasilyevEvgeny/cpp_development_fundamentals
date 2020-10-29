// https://www.coursera.org/learn/c-plus-plus-white/programming/pZwQ4/klass-rational

#include <iostream>

using namespace std;

class Rational {
public:
    Rational() {
    	numerator = 0;
    	denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
    	numerator = new_numerator;
    	denominator = new_denominator;
    	NormalizeRational(numerator, denominator);
    }

    int Numerator() const {
    	return numerator;
    }

    int Denominator() const {
    	return denominator;
    }

    int Calculate_gcd (int a, int b) {
        return b ? Calculate_gcd(b, a % b) : a;
    }

    int ChangeSign(int n) {
    	return -n;
    }

    void NormalizeRational(int& numerator, int& denominator) {
    	int gcd = Calculate_gcd(abs(numerator), abs(denominator));
    	numerator /= gcd;
    	denominator /= gcd;

    	if (denominator < 0) {
    		denominator = ChangeSign(denominator);
    		numerator = ChangeSign(numerator);
    	}
    }

private:
    int numerator;
    int denominator;
};

int main() {
    /*{
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }*/

	const Rational r(0, -1);
	cout << r.Numerator() << endl;
	cout << r.Denominator() << endl;


    //cout << "OK" << endl;
    return 0;
}
