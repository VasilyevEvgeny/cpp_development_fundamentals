//
// Created by evasilyev on 11/2/2020.
//

#ifndef INC_2_YELLOW_BELT_QUERY_H
#define INC_2_YELLOW_BELT_QUERY_H

#include <iostream>
#include <vector>
#include <string>

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
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q);

#endif //INC_2_YELLOW_BELT_QUERY_H
