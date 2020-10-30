// https://www.coursera.org/learn/c-plus-plus-yellow/programming/7T2kJ/sriedniaia-tiempieratura-2

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void PrintTemperatures(vector<int64_t>& temperatures) {
	cout << "Temperatures: ";
	for (const auto& t : temperatures)
		cout << t << " ";
	cout << endl;
}

void PrintDays(vector<size_t>& days) {
	cout << "Days: ";
	for (const auto& day : days)
		cout << day << " ";
	cout << endl;
}

int main() {

	size_t N;
	cin >> N;

	vector<int64_t> temperatures(N);

	int64_t sum = 0;
	for (size_t i = 0; i < N; ++i) {
		cin >> temperatures[i];
		sum += temperatures[i];
	}

	//PrintTemperatures(temperatures);

	int64_t avg = sum / static_cast<int64_t>(temperatures.size());

	vector<size_t> desired_days;
	for (size_t i = 0; i < N; ++i)
		if (temperatures[i] > avg)
			desired_days.push_back(i);

	//PrintDays(desired_days);

	cout << desired_days.size() << endl;
	for (const auto& day : desired_days)
		cout << day << " ";
	cout << endl;

	return 0;
}

