// https://www.coursera.org/learn/c-plus-plus-yellow/programming/AhGVS/gruppirovka-strok-po-priefiksu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool operator>(const string& lhs, const string& rhs) {
	size_t minimum = min(lhs.size(), rhs.size());
	for (size_t i = 0; i < minimum; ++i)
		if (lhs[i] > rhs[i])
			return true;
		else if (lhs[i] < rhs[i])
			return false;
	return minimum == lhs.size();

}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, string prefix) {
	auto first = lower_bound(range_begin, range_end, prefix,
			[](const string& lhs, const string& p){
					return lhs < p;
	});
	auto last = upper_bound(first, range_end, prefix,
			[](const string& lhs, const string& p){
		//cout << lhs << " " << p << endl;
				return !(lhs > p);
	});

	//cout << *first << " " << *last << endl;

	return {first, last};
}

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}


