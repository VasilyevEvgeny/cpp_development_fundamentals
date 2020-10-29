// https://www.coursera.org/learn/c-plus-plus-white/programming/gLemQ/iezhiemiesiachnyie-diela

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void NextMonth(int& index,const vector<int>& diy, vector<vector<string>>& tfd) {
    index++;
    if (index > 11)index = 0;
    vector<vector<string>> new_month = tfd;
    int a = tfd.size();
    int b = diy[index];
    tfd.resize(b);
    const int e = b - 1;
    if (a > b) {
        for (; a > b; b++) {
            tfd[e].insert(end(tfd[e]), begin(new_month[b]), end(new_month[b]));
        }
    }
    new_month.clear();
}

void Task_display(int day, const vector<vector<string>>& tfd) {
    cout << tfd[day - 1].size();
    for (auto& i : tfd[day - 1]){
        cout << " " << i;
    }
    cout << endl;
}

int main()
{
    int Q;
    cin >> Q;

    vector<int> day_in_year = { 31,28,31,30,31,30,31,31,30,31,30,31};
    vector<vector<string>> task_for_day;

    int index_of_month = 0;
    task_for_day.resize(day_in_year[index_of_month], {});

    for (int i = 0; Q > i; i++) {
        string command;
        int day;
        string task;
        cin >> command;
        if (command == "NEXT") {
            NextMonth(index_of_month, day_in_year, task_for_day);
        }
        else if (command == "DUMP") {
            cin >> day;
            Task_display(day,task_for_day);
        }
        else if (command == "ADD") {
            cin >> day >> task;
            task_for_day[day - 1].push_back(task);
        }
    }

    return 0;
} 
