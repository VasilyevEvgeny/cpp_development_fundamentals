// https://www.coursera.org/learn/c-plus-plus-white/programming/sO7Vq/final-naia-zadacha-kursa

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;

class Date {

public:
	Date() {
		year = 0;
		month = 0;
		day = 0;
	}

	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		month = new_month;
		day = new_day;
	}

	int GetYear() const {
		return year;
	}

	int GetMonth() const {
		return month;
	}

	int GetDay() const {
		return day;
	}

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear()) {
        return true;
	}
	else if (lhs.GetYear() > rhs.GetYear()) {
        return false;
    }
	else {
		if (lhs.GetMonth() < rhs.GetMonth()) {
            return true;
		}
		else if (lhs.GetMonth() > rhs.GetMonth()) {
            return false;
		}
		else {
			if (lhs.GetDay() < rhs.GetDay()) {
                return true;
			}
			else {
                return false;
            }
		}
	}
}

class Database {

public:
	void AddEvent(const Date& date, const string& event) {
		events[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		return events[date].erase(event);
	}

	int DeleteDate(const Date& date) {
		int N = events[date].size();
		events.erase(date);

		return N;
	}

	void Find(const Date& date) {
		if (events.count(date)) {
			for (auto& event : events[date])
				cout << event << endl;
		}
	}

	void Print() const {
		for (const auto& item : events) {
			for (const auto& event : item.second) {
				cout << setw(4) << setfill('0') << item.first.GetYear();
				cout << "-";
				cout << setw(2) << setfill('0') << item.first.GetMonth();
				cout << "-";
				cout << setw(2) << setfill('0') << item.first.GetDay();
				cout << " " << event << endl;
			}
		}
	}

private:
	map<Date,set<string>> events;
};

string ReadEvent(stringstream &ss) {
	string event_name;
	ss >> event_name;

	return event_name;
}

void ReadSeparator(stringstream& ss) {
	if (ss.peek() == '-') {
        ss.ignore(1);
	}
	else {
        throw exception();
	}
}

Date ReadDate(string& date_str) {
	stringstream ss(date_str);
	int year = 0, month = 0, day = 0;

	// year
	if ((ss >> year).fail()) { throw exception(); }

	// separator
	ReadSeparator(ss);

	// month
	if ((ss >> month).fail())  { throw exception(); }

	// separator
	ReadSeparator(ss);

	// day
	if ((ss >> day).fail()) { throw exception(); }

	if (month < 1 || month > 12) {
        throw runtime_error("Month value is invalid: " + to_string(month));
	}

	if (day < 1 || day > 31) {
        throw runtime_error("Day value is invalid: " + to_string(day));
	}

	string end;
	ss >> end;
	if (!end.empty())
		throw exception();
	else
		return {year, month, day};
}

bool ReadAndCheckDate(Date& date, string& date_str) {
	try { date = ReadDate(date_str); }
	catch (runtime_error& ex) {
		cout << ex.what() << endl;
		return false;
	}
	catch (...){
		cout << "Wrong date format: " << date_str << endl;
		return false;
	}

	return true;
}

int main() {
	Database db;
	Date date;
	string command, keyword, event_name, date_str;

	while(getline(cin, command)) {
		stringstream ss(command);
		ss >> keyword;
		if (keyword == "Add")
		{
			ss >> date_str;
			if (ReadAndCheckDate(date, date_str)) {
				event_name = ReadEvent(ss);
				db.AddEvent(date, event_name);
			}
		}
		else if (keyword == "Del") {
			ss >> date_str;
			if (ReadAndCheckDate(date, date_str)) {
				event_name = ReadEvent(ss);

				if (event_name.empty()) {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                }
				else {
					if (db.DeleteEvent(date, event_name)) {
                        cout << "Deleted successfully" << endl;
					}
					else {
                        cout << "Event not found" << endl;
					}
				}
			}
		}
		else if (keyword == "Find") {
			ss >> date_str;
			if (ReadAndCheckDate(date, date_str)) {
                event_name = ReadEvent(ss);
			}
			db.Find(date);
		}
		else if (keyword == "Print") {
			db.Print();
		}
		else if (keyword.empty()) {
			;
		}
		else {
			cout << "Unknown command: " << keyword << endl;
		}

		command.clear();
		keyword.clear();
		event_name.clear();
		date_str.clear();

	}

  return 0;
}
