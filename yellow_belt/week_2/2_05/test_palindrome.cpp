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



bool IsPalindrom(string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestEmptyString() {
	Assert(IsPalindrom(""), "empty string is palindrom");
}

void TestUnitString() {
	Assert(IsPalindrom("s"), "unit string is palindrom");
}

void TestStringWithDifferentSymbols() {
	for (char symbol = 32; symbol < 127; ++symbol) {
		Assert(!IsPalindrom(to_string(symbol) + "s" + to_string(symbol) + "s"), "cycle with symbol #" + to_string(symbol));
	}
	Assert(!IsPalindrom("abccb a"), "spaces are considered");
	Assert(!IsPalindrom("abc ecba"), "spaces are considered");
	Assert(!IsPalindrom(" s s s s s"), "space in the beginning");
	Assert(!IsPalindrom("s s s s s "), "space in the end");
	Assert(IsPalindrom("s s s s s"), "many spaces");
	Assert(IsPalindrom("  "), "2 spaces");
	Assert(IsPalindrom("   "), "3 spaces");
	Assert(IsPalindrom("    "), "4 spaces");
	Assert(!IsPalindrom(" s"), " s");
	Assert(!IsPalindrom("s "), "s ");

}

void TestTypicalExamples() {
	Assert(IsPalindrom("madam"), "madam");
	Assert(!IsPalindrom("aefa"), "aefa");
	Assert(!IsPalindrom("abefba"), "abefba");
	Assert(!IsPalindrom("abcefcba"), "abefba");
	Assert(!IsPalindrom("abcdefdcba"), "abefba");

	string long_string_true, long_string_false1, long_string_false2;
	string side = "", center_true = "bb", center_false1 = "bc", center_false2 = "bb ";
	size_t MAX = 1000;
	for (size_t i = 0; i < MAX; ++i)
		side += "a";
	long_string_true = side + center_true + side;
	long_string_false1 = side + center_false1 + side;
	long_string_false2 = side + center_false2 + side;
	Assert(IsPalindrom(long_string_true), "long_string_true");
	Assert(!IsPalindrom(long_string_false1), "long_string_false1");
	Assert(!IsPalindrom(long_string_false2), "long_string_false2");
}


int main() {
  TestRunner runner;
  runner.RunTest(TestEmptyString, "TestEmptyString");
  runner.RunTest(TestUnitString, "TestUnitString");
  runner.RunTest(TestStringWithDifferentSymbols, "TestStringWithDifferentSymbols");
  runner.RunTest(TestTypicalExamples, "TestTypicalExamples");




  return 0;
}
