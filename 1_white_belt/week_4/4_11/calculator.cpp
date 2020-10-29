// https://www.coursera.org/learn/c-plus-plus-white/programming/bshor/kal-kuliator-obyknoviennykh-drobiei

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

using namespace std;

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational {

public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        if (new_denominator == 0) {
          throw invalid_argument("Invalid argument");
        }

        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);

        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;

        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};


bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
      lhs.Denominator() == rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
	    throw domain_error("Division by zero");
	}

	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
    int n, d;
    char c;
    is >> n >> c >> d;
    if (is && c == '/') {
        r = Rational(n, d);
    }

    return is;
}

ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}


int main() {

	string left;
	cin >> left;

	try {
		stringstream ss_left(left);
		int numerator = 0;
		int denominator = 0;
		ss_left >> numerator;
		ss_left.ignore(1);
		ss_left >> denominator;

		Rational r1(numerator, denominator);

		char op;
		cin >> op;

		string right;
		cin >> right;


		stringstream ss_right(right);
		numerator = 0;
		denominator = 0;
		ss_right >> numerator;
		ss_right.ignore(1);
		ss_right >> denominator;

		Rational r2(numerator, denominator);

		if (op == '+') {
            cout << r1 + r2;
		}
		else if (op == '-') {
            cout << r1 - r2;
		}
		else if (op == '*') {
            cout << r1 * r2;
		}
		else if (op == '/') {
            cout << r1 / r2;
		}
	}
	catch (invalid_argument& ex) {
		cout << ex.what();
	}
	catch (domain_error& ex) {
	    cout << ex.what();
	}

	return 0;
}

