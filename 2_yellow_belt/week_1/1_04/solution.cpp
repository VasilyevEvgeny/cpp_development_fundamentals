/*#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

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



void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}


class TeamTasks {
public:
  const TasksInfo& GetPersonTasksInfo(const string& person) {
      return Tasks[person];
  }

  void AddNewTask(const string& person){
      Tasks[person][TaskStatus::NEW]++;
  }

  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count){

         TasksInfo untouched;
         TasksInfo updated;

         if (Tasks.count(person))
            untouched=Tasks[person];
        else
            return tie (updated, untouched);

         untouched.erase(TaskStatus::DONE);

         for (size_t i=0; i<3; i++){   //листаем массив TaskInfo по ключам
            if (!task_count)          //TaskStatus используя числовые
                break;                //значения этих ключей

            TaskStatus status=static_cast<TaskStatus>(i);
            TaskStatus next_status=static_cast<TaskStatus>(i+1);

            if (untouched.count(status) && task_count>=untouched[status]){

                updated [next_status]=untouched[status];
                task_count-=untouched[status];
                untouched.erase(status);

                Tasks[person].erase(status);
                Tasks[person][next_status]+=updated [next_status];
            }
            else if (untouched.count(status) && task_count<untouched[status]){

                updated [next_status]=task_count;
                untouched [status]-=task_count;

                Tasks[person][status]-=task_count;
                Tasks[person][next_status]+=updated [next_status];

                break;
            }
         }
         return tie (updated, untouched);
      }

private:
    map<string, TasksInfo> Tasks;
};



int main() {
	TeamTasks tasks;

	tasks.AddNewTask("test");

	tasks.PerformPersonTasks("test", 3);

	PrintTasksInfo(tasks.GetPersonTasksInfo("test"));

	/*tasks.PerformPersonTasks("test",3);

	PrintTasksInfo(tasks.GetPersonTasksInfo("test"));*/


	/*return 0;
}*/
