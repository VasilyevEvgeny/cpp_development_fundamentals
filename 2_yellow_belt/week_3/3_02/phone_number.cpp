// https://www.coursera.org/learn/c-plus-plus-yellow/programming/7FjGE/riealizovat-klass-obiavliennyi-v-zagholovochnom-failie

#include "phone_number.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <limits>

using namespace std;

void CheckSeparator(istringstream& iss, char separator) {
	if (iss.peek() != separator)
		throw invalid_argument(to_string(separator));
	else
		iss.ignore(1);
}

void CheckField(string& str, size_t length) {
	if (str.empty() || str.size() > length)
		throw invalid_argument(str);
}

PhoneNumber::PhoneNumber(const string &international_number) {
	istringstream iss(international_number);
	CheckSeparator(iss, '+');
	getline(iss, country_code_, '-');
	CheckField(country_code_, 3);
	getline(iss, city_code_, '-');
	CheckField(city_code_, 3);
	getline(iss, local_number_);
	CheckField(local_number_, numeric_limits<size_t>::max());


	//;
	//CheckSeparator(iss, '+');
	//int country_code;
	//iss >> country_code_;
	/*CheckField(country_code_, 3);
	CheckSeparator(iss, '-');
	iss >> city_code_;
	CheckField(city_code_, 3);
	CheckSeparator(iss, '-');
	iss >> local_number_;
	CheckField(local_number_, numeric_limits<size_t>::max());*/
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

/*int main() {
	PhoneNumber phone("+7-1233");
	//cout << phone.GetCountryCode() << endl;
	//cout << phone.GetCityCode() << endl;
	//cout << phone.GetLocalNumber() << endl;
	cout << phone.GetInternationalNumber() << endl;

	return 0;
}*/
