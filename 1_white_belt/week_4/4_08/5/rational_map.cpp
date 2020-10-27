#include <iostream>
#include <map>
#include <set>
#include <vector>
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


private:
    int numerator;
    int denominator;

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

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а


bool operator<(const Rational& rational_left, const Rational& rational_right) {
	if (rational_left.Numerator() * rational_right.Denominator() <
			rational_right.Numerator() * rational_left.Denominator()) {
		return true;
	}
	else
		return false;

}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
