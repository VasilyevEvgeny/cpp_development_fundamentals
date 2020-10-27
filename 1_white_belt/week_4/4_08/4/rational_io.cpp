#include <iostream>
#include <sstream>
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


// Реализуйте для класса Rational операторы << и >>

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.Numerator() << "/" << rational.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
	int numerator = 0;
	int denominator = 0;
	stream >> numerator;
	stream.ignore(1);
	stream >> denominator;
	if (denominator != 0)
		rational = Rational(numerator, denominator);

	return stream;
}


int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
