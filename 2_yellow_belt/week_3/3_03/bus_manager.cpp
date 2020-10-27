/*
 * bus_manager.cpp
 *
 *  Created on: May 13, 2018
 *      Author: evgeny
 */

#include "bus_manager.h"

#include <algorithm>

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	buses_to_stops[bus] = stops;
	for (string stop : stops) {
	  stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	string no_stop = "No stop";
	vector<string> buses_for_stop;
	if (stops_to_buses.count(stop) != 0) {
		for (const string& bus : stops_to_buses.at(stop))
			if (count(buses_for_stop.begin(), buses_for_stop.end(), bus) == 0)
				buses_for_stop.push_back(bus);
	}
	return {no_stop, buses_for_stop};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
	string no_buses = "No buses";
	map<string, vector<string>> all_buses = buses_to_stops;
	map<string, vector<string>> all_buses_stops = stops_to_buses;

	return {no_buses, all_buses, all_buses_stops};
}


