// https://www.coursera.org/learn/c-plus-plus-red/programming/8O9dd/sistiema-bronirovaniia-otieliei

#include <iostream>
#include <queue>
#include <map>

struct Booking {
    int64_t time;
    std::string hotel_name;
    size_t client_id;
    size_t room_count;
};

class HotelsManager {
public:
    HotelsManager() = default;

    void Book(const int64_t time, const std::string& hotel_name, const size_t client_id, const size_t room_count) {
        bookings_.push({time, hotel_name, client_id, room_count});
        clients_[hotel_name][client_id] += room_count;
        rooms_[hotel_name] += room_count;

        // update bookings
        while (!bookings_.empty() && bookings_.front().time + 86400 <= time) {
            auto it = bookings_.front();
            clients_[it.hotel_name][it.client_id] -= it.room_count;
            if (clients_[it.hotel_name][it.client_id] == 0) {
                clients_[it.hotel_name].erase(it.client_id);
            }
            rooms_[it.hotel_name] -= it.room_count;
            bookings_.pop();
        }
    }

    size_t Clients(const std::string& hotel_name) {
        return clients_[hotel_name].size();
    }

    size_t Rooms(const std::string& hotel_name) {
        return rooms_[hotel_name];
    }

private:
    std::queue<Booking> bookings_;
    std::map<std::string, std::map<size_t, size_t>> clients_;
    std::map<std::string, size_t> rooms_;

};


int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    HotelsManager hotels_manager;
    size_t Q;
    std::cin >> Q;

    for (size_t q = 0; q < Q; ++q) {
        std::string command;
        std::string hotel_name;

        std::cin >> command;
        if (command == "BOOK") {
            int64_t time;
            size_t client_id;
            size_t room_count;
            std::cin >> time >> hotel_name >> client_id >> room_count;

            hotels_manager.Book(time, hotel_name, client_id, room_count);
        }
        else if (command == "CLIENTS") {
            std::cin >> hotel_name;
            std::cout << hotels_manager.Clients(hotel_name) << std::endl;
        }
        else if (command == "ROOMS") {
            std::cin >> hotel_name;
            std::cout << hotels_manager.Rooms(hotel_name) << std::endl;
        }
    }

    return 0;
}