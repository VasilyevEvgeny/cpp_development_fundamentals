#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


void update_buses_for_stops(const map<string,vector<string>>& stops_for_buses, map<string,vector<string>>& buses_for_stops) {
	for (const auto& item : stops_for_buses) {
		for (const auto& station : item.second) {
			int flag = 0;
			for (unsigned int i = 0; i < buses_for_stops[station].size(); ++i) {
				if (buses_for_stops[station][i] == item.first) {
					++flag;
					break;
				}
			}
			if (!flag)
				buses_for_stops[station].push_back(item.first);
		}
	}
}

int main() {

	int Q;
	cin >> Q;

	map<string,vector<string>> stops_for_buses, buses_for_stops;

	string command;
	for(int q = 0; q < Q; ++q) {
		cin >> command;
		if (command == "NEW_BUS") {
			string bus;
			cin >> bus;
			int stop_count;
			cin >> stop_count;
			string stop;
			for (int i = 0; i < stop_count; ++i) {
				cin >> stop;
				stops_for_buses[bus].push_back(stop);
			}
			update_buses_for_stops(stops_for_buses, buses_for_stops);
		}
		else if (command == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			if (buses_for_stops.count(stop) == 0) {
				cout << "No stop";
			}
			else {
				for (const auto& bus : buses_for_stops[stop])
					cout << bus << " ";
			}
			cout << endl;

		}
		else if (command == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (stops_for_buses.count(bus) != 0){
				for (const auto& stop : stops_for_buses[bus]) {
					cout << "Stop " << stop << ":";
					if (buses_for_stops[stop].size() == 1 && buses_for_stops[stop][0] == bus)
						cout << " no interchange";
					else
						for (const auto& bus_for_stop : buses_for_stops[stop])
							if (bus_for_stop != bus)
								cout << " " << bus_for_stop;
					cout << endl;
				}
			}
			else
				cout << "No bus" << endl;
		}
		else if (command == "ALL_BUSES") {
			if (stops_for_buses.size() > 0) {
				for (const auto& item : stops_for_buses) {
					cout << "Bus " << item.first << ":";
					for (const auto& stop : item.second) {
						cout << " " << stop;
					}
					cout << endl;
				}
				/*for (const auto& item : buses_for_stops) {
					cout << "Stop " << item.first << ":";
					for (const auto& bus : item.second) {
						cout << " " << bus;
					}
					cout << endl;
				}*/
			}
			else {
				cout << "No buses" << endl;
			}
		}

	}

	return 0;
}

