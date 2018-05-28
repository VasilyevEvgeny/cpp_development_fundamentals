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

// Реализуйте для класса Rational операторы ==, + и -

bool operator== (const Rational& rational_left, const Rational& rational_right) {
	if (rational_left.Numerator() == rational_right.Numerator() &&
			rational_left.Denominator() == rational_right.Denominator())
		return true;
	else
		return false;
}

Rational operator+ (const Rational& rational_left, const Rational& rational_right) {
	int gen_denominator = rational_left.Denominator() * rational_right.Denominator();
	int gen_numerator = rational_left.Numerator() * rational_right.Denominator() +
			rational_right.Numerator() * rational_left.Denominator();
	return {gen_numerator, gen_denominator};
}

Rational operator- (const Rational& rational_left, const Rational& rational_right) {
	int gen_denominator = rational_left.Denominator() * rational_right.Denominator();
	int gen_numerator = rational_left.Numerator() * rational_right.Denominator() -
			rational_right.Numerator() * rational_left.Denominator();
	return {gen_numerator, gen_denominator};
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

   {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
