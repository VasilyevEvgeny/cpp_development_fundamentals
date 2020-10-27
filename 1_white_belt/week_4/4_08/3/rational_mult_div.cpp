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


// Реализуйте для класса Rational операторы * и /

Rational operator* (const Rational& rational_left, const Rational& rational_right) {
	int gen_denominator = rational_left.Denominator() * rational_right.Denominator();
	int gen_numerator = rational_left.Numerator() * rational_right.Numerator();
	return {gen_numerator, gen_denominator};
}

Rational operator/ (const Rational& rational_left, const Rational& rational_right) {
	int gen_denominator = rational_left.Denominator() * rational_right.Numerator();
	int gen_numerator = rational_left.Numerator() * rational_right.Denominator();
	return {gen_numerator, gen_denominator};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
