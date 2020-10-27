/*
 * figures.cpp
 *
 *  Created on: May 23, 2018
 *      Author: evgeny
 */


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
	Triangle(const string& name, const double& a, const double& b, const double& c)
		: name_(name)
		, a_(a), b_(b), c_(c) {}

	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return a_ + b_ + c_;
	}

	double Area() const override {
		double p = Perimeter() / 2.0;
		return sqrt(p * (p - a_) * (p - b_) * (p - c_));
	}

private:
	const string name_ = "";
	const double a_;
	const double b_;
	const double c_;
};



class Rect : public Figure {
public:
	Rect(const string& name, const double& a, const double& b)
		: name_(name)
		, a_(a), b_(b) {}

	string Name() const override {
			return name_;
	}

	double Perimeter() const override {
		return 2.0 * (a_ + b_);
	}

	double Area() const override {
		return a_ * b_;
	}


private:
	const string name_ = "";
	const double a_;
	const double b_;
};



class Circle : public Figure {
public:
	Circle(const string& name, const double& r)
		: name_(name)
		, r_(r) {}

	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return 2.0 * pi_ * r_;
	}

	double Area() const override {
		return pi_ * r_ * r_;
	}

private:
	const string name_ = "";
	const double r_;
	const double pi_ = 3.14;
};



shared_ptr<Figure> CreateFigure(istream& is) {
	string name;
	is >> name;
	if (name == "TRIANGLE") {
		double a = 0.0, b = 0.0, c = 0.0;
		is >> a;
		is >> b;
		is >> c;
		return make_shared<Triangle>(name, a, b, c);
	}
	else if (name == "RECT") {
		double a = 0.0, b = 0.0;
		is >> a;
		is >> b;
		return make_shared<Rect>(name, a, b);
	}
	else if (name == "CIRCLE") {
		double r = 0.0;
		is >> r;
		return make_shared<Circle>(name, r);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);
		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
		  for (const auto& current_figure : figures) {
			cout << fixed << setprecision(3)
				 << current_figure->Name() << " "
				 << current_figure->Perimeter() << " "
				 << current_figure->Area() << endl;
		  }
		}
	}
	return 0;
}
