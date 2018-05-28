#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {

	int Q;
	cin >> Q;

	vector<string> stops;
	map<vector<string>,int> routes;
	int n_of_route = 1;
	for (int q = 0; q < Q; ++q) {
		int N;
		cin >> N;
		string stop;
		for (int n = 0; n < N; ++n) {
			cin >> stop;
			stops.push_back(stop);
		}
		if (routes.count(stops) == 0) {
			routes[stops] = n_of_route++;
			cout << "New bus " << n_of_route-1 << endl;
		}
		else
			cout << "Already exists for " << routes[stops] << endl;

		stops.clear();

	}

	return 0;
}
