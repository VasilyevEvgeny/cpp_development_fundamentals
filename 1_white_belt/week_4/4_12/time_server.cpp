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
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля LastFetchedTime
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */

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
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}*/
