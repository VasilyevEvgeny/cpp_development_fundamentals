/*
 * query.cpp
 *
 *  Created on: May 13, 2018
 *      Author: evgeny
 */

#include "query.h"

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



