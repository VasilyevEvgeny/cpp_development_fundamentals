#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <optional>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; ++i)
#define fr2(i,a,b) for (int i = a; i < b; ++i)

optional<I64> sum(I64 a, I64 b) {
    if (a >= 0) {
        if (b >= 0) {
            if (a <= INT64_MAX - b) {
                return a + b;
            }
            else {
                return nullopt;
            }
        }
        else {
            return a + b;
        }
    }
    else {
        if (b >= 0) {
            return a + b;
        }
        else {
            if (a >= INT64_MIN - b) {
                return a + b;
            }
            else {
                return nullopt;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    I64 a, b;
    cin >> a >> b;

    const auto res = sum(a, b);
    if (res) {
        cout << *res;
    }
    else {
        cout << "Overflow!";
    }

    return 0;
}