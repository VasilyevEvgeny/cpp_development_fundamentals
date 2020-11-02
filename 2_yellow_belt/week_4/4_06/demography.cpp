// https://www.coursera.org/learn/c-plus-plus-yellow/programming/iFaYj/diemoghrafichieskiie-pokazatieli

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*enum class Gender {
  FEMALE,
  MALE
};


struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}*/

void PrintAge(string name, vector<Person> v) {
	cout << name << ComputeMedianAge(begin(v), end(v)) << endl;;
}

void PrintStats(vector<Person> persons) {
	/* all_people */
	PrintAge("Median age = ", persons);

	/* females */
	auto it1 = partition(begin(persons), end(persons),
			[](Person p){
				return p.gender == Gender::FEMALE;
	});
	vector<Person> part1 = {begin(persons), it1};
	PrintAge("Median age for females = ", part1);

	/* males */
	auto it2 = partition(begin(persons), end(persons),
			[](Person p){
				return p.gender == Gender::MALE;
	});
	vector<Person> part2 = {begin(persons), it2};
	PrintAge("Median age for males = ", part2);

	/* employed females */
	auto it3 = partition(begin(persons), end(persons),
			[](Person p){
				return p.gender == Gender::FEMALE && p.is_employed == true;
	});
	vector<Person> part3 = {begin(persons), it3};
	PrintAge("Median age for employed females  = ", part3);

	/* unemployed females */
	auto it4 = partition(begin(persons), end(persons),
			[](Person p){
				return p.gender == Gender::FEMALE && p.is_employed == false;
	});
	vector<Person> part4 = {begin(persons), it4};
	PrintAge("Median age for unemployed females  = ", part4);

	/* employed males */
	auto it5 = partition(begin(persons), end(persons),
			[](Person p){
				return p.gender == Gender::MALE && p.is_employed == true;
	});
	vector<Person> part5 = {begin(persons), it5};
	PrintAge("Median age for employed males  = ", part5);

	/* employed males */
	auto it6 = partition(begin(persons), end(persons),
			[](Person p){
				return p.gender == Gender::MALE && p.is_employed == false;
	});
	vector<Person> part6 = {begin(persons), it6};
	PrintAge("Median age for unemployed males  = ", part6);
}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
