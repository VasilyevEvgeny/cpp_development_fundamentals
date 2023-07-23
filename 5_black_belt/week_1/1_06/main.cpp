#include "requests.h"
//#include "tests.h"

using namespace std;

int main() {
	//RunAllTests();

	cout.precision(6);

	try {
		Json::Document doc = Json::Load(cin);
		Json::Dict dict = doc.GetRoot().AsMap();
		const auto base_requests = Descriptions::ReadDescriptions(dict["base_requests"].AsArray());
		const auto routing_settings = dict["routing_settings"].AsMap();
		TransportCatalog db(base_requests, routing_settings);
		const auto stat_requests = dict["stat_requests"].AsArray();
		const auto responses = Requests::ProcessAll(db, stat_requests);
		Json::PrintValue(responses, cout);
	}
	catch (const runtime_error & e) {
		cerr << "Exception: " << e.what() << '\n';
	}

	return 0;
}
