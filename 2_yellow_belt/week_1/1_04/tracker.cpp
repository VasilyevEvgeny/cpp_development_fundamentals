// https://www.coursera.org/learn/c-plus-plus-yellow/programming/f9Art/triekier-zadach

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template<class T> std::ostream& operator << (std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

/*
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
*/

std::ostream& operator<< (std::ostream &os, const TaskStatus& ts) {
    if (ts == TaskStatus::NEW) { os << "NEW"; }
    else if (ts == TaskStatus::IN_PROGRESS) { os << "IN_PROGRESS"; }
    else if (ts == TaskStatus::TESTING) { os << "TESTING"; }
    else { os << "DONE"; }

    return os;
}

std::ostream& operator<< (std::ostream &os, const TasksInfo &m) {
    for (auto& item : m) {
        os << "{" << item.first << "->" << item.second << "} ";
    }

    return os;
}



// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return data.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        data[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        if (data.find(person) == data.end()) {
            return {};
        }

        if (verbose) {
            cout << "-------------> PerformPersonTasks!" << endl;
        }

        TasksInfo updated, untouched(data.at(person));
        vector<TaskStatus> statuses = {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, TaskStatus::DONE};

        vector<int> ns(n_statuses);
        for (size_t i = 0; i < n_statuses; ++i) {
            ns[i] = data.at(person)[statuses[i]];
        }

        for (size_t i = 0; i < n_statuses - 1; ++i) {
            auto cur_status = statuses[i];
            auto nxt_status = statuses[i + 1];

            if (verbose) {
                cout << "===================================" << endl;
                cout << "cur_status: " << i << ", nxt status = " << i + 1 << endl;
            }

            while (ns[i] && task_count) {

                // cur_status
                data.at(person).at(cur_status)--;
                untouched.at(cur_status)--;

                // nxt_status
                data.at(person)[nxt_status]++;
                updated[nxt_status]++;

                // upd cnt
                ns[i]--;
                task_count--;
            }

            if (verbose) {
                cout << "ns[i] = " << ns[i] << endl;
                cout << "task_count = " << task_count << endl;
                cout << "data = "; PrintTasksInfo(data.at(person));
                cout << "untouched = "; PrintTasksInfo(untouched);
                cout << "updated = "; PrintTasksInfo(updated);
            }

        }

        untouched.erase(TaskStatus::DONE);

        clear_task_info(data.at(person));
        clear_task_info(updated);
        clear_task_info(untouched);

        if (verbose) {
            cout << "=================" << endl;
            cout << "data: " << data.at(person) << endl;
            cout << "updated: " << updated << endl;
            cout << "untouched: " << untouched << endl;
        }

        return {updated, untouched};
    }

private:
    map<string, TasksInfo> data;
    const size_t n_statuses = 4;
    const bool verbose = false;

    static void clear_task_info(TasksInfo& ti) {
        auto copy_ti(ti);
        for (auto item : copy_ti) {
            if (!item.second) {
                ti.erase(item.first);
            }
        }
    }
};


/*
int main() {

/////////////  1
//    TeamTasks tasks;
//    tasks.AddNewTask("Ilia");
//    for (int i = 0; i < 3; ++i) {
//        tasks.AddNewTask("Ivan");
//    }
//    cout << "Ilia's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//    cout << "Ivan's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//    TasksInfo updated_tasks, untouched_tasks;
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);



/////////////  2
    TeamTasks tasks;
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tasks.PerformPersonTasks("Alice", 5);
    tasks.PerformPersonTasks("Alice", 5);
    tasks.PerformPersonTasks("Alice", 1);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    tasks.PerformPersonTasks("Alice", 2);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    tasks.PerformPersonTasks("Alice", 4);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));


    return 0;
}

*/
