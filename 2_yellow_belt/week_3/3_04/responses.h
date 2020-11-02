#ifndef INC_2_YELLOW_BELT_RESPONSES_H
#define INC_2_YELLOW_BELT_RESPONSES_H

#include <vector>
#include <map>
#include <string>

using namespace std;

struct BusesForStopResponse {
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops_for_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);



#endif //INC_2_YELLOW_BELT_RESPONSES_H
