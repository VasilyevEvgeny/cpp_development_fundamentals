/*
 * refactoring.cpp
 *
 *  Created on: May 23, 2018
 *      Author: evgeny
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
public:
	Person(const string& type, const string name)
		: Type(type), Name(name) {}

	string GetType() const {
		return Type;
	}

	string GetName() const {
		return Name;
	}

	string PrintName() const {
		return Type + ": " + Name;
	}

	void Walking_To(const string& destination) const {
		cout << PrintName() << " walks to: " << destination << endl;
	}

	virtual void Walk(const string& destination) const {
		Walking_To(destination);
	}


private:
	const string Type = "";
	const string Name = "";
};


class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong)
		: Person("Student", name)
		, FavouriteSong(favouriteSong) {}

    void Learn() const {
    	cout << PrintName() << " learns" << endl;
    }

    void SingSong() const {
    	cout << PrintName() << " sings a song: " << FavouriteSong << endl;
    }

    void Walk(const string& destination) const override {
    	Walking_To(destination);
    	SingSong();
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject)
		: Person("Teacher", name)
        , Subject(subject) {}

    void Teach() {
        cout << PrintName() << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name)
		: Person("Policeman", name) {}


    void Check(const Person& person) {
    	cout << PrintName() << " checks " << person.GetType() << ". "
    		 << person.GetType() << "'s name is " << person.GetName() << endl;
    }
};


void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
    	person.Walk(p);
    }
}



int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, {"Moscow", "London"});
	p.Check(s);
	VisitPlaces(s, {"Moscow", "London"});
	return 0;
}



