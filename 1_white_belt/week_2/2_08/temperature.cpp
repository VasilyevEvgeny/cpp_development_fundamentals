// https://www.coursera.org/learn/c-plus-plus-white/programming/oGdDI/sriedniaia-tiempieratura

#include <iostream>
#include <vector>

using namespace std;



int main() {

	int N;
	cin >> N;

	vector<int> days(N);
	for(auto& d : days)
		cin >> d;

	int mean = 0;
	for (int i = 0; i < N; ++i)
		mean += days[i];
	mean /= N;

	int K = 0;
	vector<int> res_vector;
	for (int i = 0; i < N; ++i)
		if (days[i] > mean) {
			K++;
			res_vector.push_back(i);
		}

	cout << K << endl;
	for (auto d : res_vector)
		cout << d << " ";

	return 0;
}

