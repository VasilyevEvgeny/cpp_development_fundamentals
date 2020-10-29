// https://www.coursera.org/learn/c-plus-plus-white/programming/4FQn4/imiena-i-familii-1

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

class Person {
	public:
		void ChangeFirstName(int year, const string& first_name) {
			first_name_dict[year] = first_name;
		}
		void ChangeLastName(int year, const string& last_name) {
			last_name_dict[year] = last_name;
		}
		string GetFullName(int year) {
			int year_for_first_name = 0, year_for_last_name = 0;
			for (const auto& item : first_name_dict) {
				if (item.first <= year)
					year_for_first_name = item.first;
			}
			for (const auto& item : last_name_dict) {
				if (item.first <= year)
					year_for_last_name = item.first;
			}

			if (year_for_first_name == 0 && year_for_last_name == 0)
				return "Incognito";
			else if (year_for_first_name != 0 && year_for_last_name == 0)
				return first_name_dict[year_for_first_name] + " with unknown last name";
			else if (year_for_first_name == 0 && year_for_last_name != 0)
				return last_name_dict[year_for_last_name] + " with unknown first name";
			else
				return first_name_dict[year_for_first_name] + " " + last_name_dict[year_for_last_name];
		}
	private:
		map<int,string> first_name_dict, last_name_dict;

};


/*int main() {

	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
	cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
	cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
	cout << person.GetFullName(year) << endl;
	}

	return 0;
}*/

