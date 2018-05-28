#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Specialization {
	string val;
	explicit Specialization(const string& new_val) {
		val = new_val;
	}
};

struct Course {
	string val;
	explicit Course(const string& new_val) {
		val = new_val;
	}
};

struct Week {
	string val;
	explicit Week(const string& new_val) {
		val = new_val;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(const Specialization& new_specialization, const Course& new_course, const Week& new_week) {
		specialization = new_specialization.val;
		course = new_course.val;
		week = new_week.val;
	}
};

//int main() {

	/*LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);*/

	/*LectureTitle title("C++", "White belt", "4th");*/

	/*LectureTitle title(string("C++"), string("White belt"), string("4th"));*/

	/*LectureTitle title = {"C++", "White belt", "4th"};*/

	/*LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};*/

	/*LectureTitle title(
	    Course("White belt"),
	    Specialization("C++"),
	    Week("4th")
	);*/

	/*LectureTitle title(
	    Specialization("C++"),
	    Week("4th"),
	    Course("White belt")
	);*/

//	return 0;
//}

