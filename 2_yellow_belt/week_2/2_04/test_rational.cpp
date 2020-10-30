// https://www.coursera.org/learn/c-plus-plus-yellow/programming/KJ7Sh/tiesty-dlia-klassa-rational

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

/*int GreatestCommonDivisor(int a, int b) {
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
}*/

void TestDefaultConstructor() {
	Rational r;
	AssertEqual(r.Numerator(), 0, "null numerator");
	AssertEqual(r.Denominator(), 1, "unit denominator");
}

void TestReduction() {
	Rational r(4, 6);
	AssertEqual(r.Numerator(), 2, "numerator of '4/6' equals to 2");
	AssertEqual(r.Denominator(), 3, "denominator of '4/6' equals to 3");
}

void TestCorrectNegative() {
	Rational r(1,-1);
	AssertEqual(r.Numerator(), -1, "numerator of '1/-1' equals to -1");
	AssertEqual(r.Denominator(), 1, "denominator of '1/-1' equals to 1");
}

void TestPositiveFraction() {
	Rational r1(1,1);
	AssertEqual(r1.Numerator(), 1, "numerator of '1/1' equals to 1");
	AssertEqual(r1.Denominator(), 1, "denominator of '1/1' equals to 1");

	Rational r2(-1,-1);
	AssertEqual(r2.Numerator(), 1, "numerator of '-1/-1' equals to 1");
	AssertEqual(r2.Denominator(), 1, "denominator of '-1/-1' equals to 1");
}

void TestNullNumerator() {
	Rational r(0, 2);
	AssertEqual(r.Numerator(), 0, "numerator of '0/2' equals to 0");
	AssertEqual(r.Denominator(), 1, "denominator of '0/2' equals to 1");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
  runner.RunTest(TestReduction, "TestReduction");
  runner.RunTest(TestCorrectNegative, "TestCorrectNegative");
  runner.RunTest(TestPositiveFraction, "TestPositiveFraction");
  runner.RunTest(TestNullNumerator, "TestNullNumerator");

  return 0;
}
