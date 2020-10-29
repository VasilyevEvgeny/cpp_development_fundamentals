// https://www.coursera.org/learn/c-plus-plus-white/programming/F7WBk/avtobusnyie-ostanovki-3

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {

	int Q;
	cin >> Q;

	map<set<string>, int> stations;
	set<string> stops;

	int N;
	string stop;

	int n_route = 1;
	for (int q = 0; q < Q; ++q) {
		cin >> N;
		for (int n = 0; n < N; ++n) {
			cin >> stop;
			stops.insert(stop);
		}
		if (stations.count(stops) == 0) {
			stations[stops] = n_route;
			cout << "New bus " << n_route << endl;
			n_route++;
		}
		else {
			cout << "Already exists for " << stations[stops] << endl;
		}

		stops.clear();
	}

	return 0;
}

