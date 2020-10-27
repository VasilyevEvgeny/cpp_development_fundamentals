#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  int n;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	q.bus = "";
	q.stop = "";
	q.n = 0;
	q.stops.clear();

	string operation_code;
	is >> operation_code;
	if (operation_code == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		is >> q.n;
		for (int i = 0; i < q.n; ++i) {
			string stop;
			is >> stop;
			q.stops.push_back(stop);
		}
	}
	else if (operation_code == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (operation_code == "ALL_BUSES")
		q.type = QueryType::AllBuses;



	return is;
}

struct BusesForStopResponse {
	string no_stop;
	vector<string> buses_for_stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (!r.buses_for_stop.empty()) {
		for (const string& bus : r.buses_for_stop)
			os << bus << " ";
	} else {
		os << r.no_stop;
	}

	return os;
}

struct StopsForBusResponse {
	string no_bus;
	string bus;
	vector<string> stops_list;
	map<string, vector<string>> stops_for_bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (!r.stops_list.empty()) {
		for (size_t i = 0; i < r.stops_list.size(); ++i) {
			string stop = r.stops_list[i];
			os << "Stop " << stop << ":";
			if (r.stops_for_bus.at(stop).size() == 1) {
				os << " no interchange";
			} else {
				for (const auto& bus : r.stops_for_bus.at(stop))
					if (r.bus != bus)
						os << " " << bus;
			}
			if (i != r.stops_list.size()-1)
				os << endl;
		}
	} else {
		os << r.no_bus;
	}

  return os;
}

struct AllBusesResponse {
  string no_buses;
  map<string, vector<string>> all_buses;
  map<string, vector<string>> all_buses_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (!r.all_buses.empty()) {
		size_t i = 0;
		for (const auto& item : r.all_buses) {
			os << "Bus " << item.first << ":";
			for (const auto& stop : item.second) {
				os << " " << stop;
			}
			if (i != r.all_buses.size()-1)
				os << endl;
			++i;
		}
	}
	else {
		os << r.no_buses;
	}
	/*os << endl;
	os << endl;
	if (!r.all_buses_stops.empty()) {
			size_t i = 0;
			for (const auto& item : r.all_buses_stops) {
				os << "Stop " << item.first << ":";
				for (const auto& stop : item.second) {
					os << " " << stop;
				}
				if (i != r.all_buses_stops.size()-1)
					os << endl;
				++i;
			}
		}
		else {
			os << r.no_buses;
		}*/

  return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (string stop : stops) {
		  stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		string no_stop = "No stop";
		vector<string> buses_for_stop;
		if (stops_to_buses.count(stop) != 0) {
			for (const string& bus : stops_to_buses.at(stop))
				if (count(buses_for_stop.begin(), buses_for_stop.end(), bus) == 0)
					buses_for_stop.push_back(bus);
		}
		return {no_stop, buses_for_stop};
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		string no_bus = "No bus";
		vector<string> stops_list;
		map<string, vector<string>> stops_for_bus = stops_to_buses;
		if (buses_to_stops.count(bus) != 0) {
			for (const auto& stop : buses_to_stops.at(bus)) {
				stops_list.push_back(stop);
			}
		}
		return {no_bus, bus, stops_list, stops_for_bus};
	}

	AllBusesResponse GetAllBuses() const {
		string no_buses = "No buses";
		map<string, vector<string>> all_buses = buses_to_stops;
		map<string, vector<string>> all_buses_stops = stops_to_buses;

		return {no_buses, all_buses, all_buses_stops};
  }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
