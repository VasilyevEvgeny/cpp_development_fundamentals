/*
 * responses.cpp
 *
 *  Created on: May 13, 2018
 *      Author: evgeny
 */

#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (!r.buses_for_stop.empty()) {
		for (const string& bus : r.buses_for_stop)
			os << bus << " ";
	} else {
		os << r.no_stop;
	}

	return os;
}


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

  return os;
}



