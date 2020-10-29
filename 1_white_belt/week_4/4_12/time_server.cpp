// https://www.coursera.org/learn/c-plus-plus-white/programming/NXqA9/rabota-s-siervierom-vriemieni

#include <iostream>
#include <exception>
#include <string>

using namespace std;

/*string AskTimeServer() {
	//return "01:02:11";
	//throw system_error(error_code());
	throw runtime_error("runtime exception");
}*/

class TimeServer {

public:
    string GetCurrentTime() {
    	try {
    		LastFetchedTime = AskTimeServer();
    		return LastFetchedTime;
    	} catch (system_error& ex) {
    		return LastFetchedTime;
    	} catch (...){
    		throw;
    	}
    }

private:
    string LastFetchedTime = "00:00:00";
};

/*int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}*/
