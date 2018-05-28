/*
 * tracker.cpp
 *
 *  Created on: May 3, 2018
 *      Author: evgeny
 */


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Перечислимый тип для статуса задачи
/*enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;*/



void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

void update_status(TaskStatus& status) {
	if (status == TaskStatus::NEW)
		status = TaskStatus::IN_PROGRESS;
	else if (status == TaskStatus::IN_PROGRESS)
		status = TaskStatus::TESTING;
	else if (status == TaskStatus::TESTING)
		status = TaskStatus::DONE;
	else if (status == TaskStatus::DONE)
		status = TaskStatus::DONE;
}

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) {
		return team[person];
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person) {
		team[person][TaskStatus::NEW]++;
		//team[person][TaskStatus::IN_PROGRESS] = 2;
		//team[person][TaskStatus::TESTING] = 4;
		//team[person][TaskStatus::DONE] = 1;
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		/*if (team[person][TaskStatus::NEW] == 5 &&
			team[person][TaskStatus::IN_PROGRESS] == 0 &&
			team[person][TaskStatus::TESTING] == 4 &&
			team[person][TaskStatus::DONE] == 1
		) {
			TasksInfo updated = {{TaskStatus::IN_PROGRESS, 2}, {}};
		TasksInfo untouched = {{TaskStatus::NEW, 3}, {TaskStatus::TESTING, 4}};

		return tie(updated, untouched);
		}*/
			/*return make_tuple(
					{TaskStatus::IN_PROGRESS : 2}, {});*/
					//make_tuple({TaskStatus::IN_PROGRESS : 2},
					//{TaskStatus::NEW : 3, TaskStatus::TESTING : 4});





		TasksInfo team_updated, team_updated_cleared;
		TasksInfo team_untouched, team_untouched_cleared;
		int new_size_for_status = 0;
		int old_size_for_status = 0;
		int remainder = 0;
		vector<TaskStatus> statuses = {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, TaskStatus::DONE};
		//TaskStatus status = TaskStatus::NEW;
		//while (task_count > 0) {
		for (const auto& status : statuses){
			if (remainder)
				team_updated[status] = remainder;

			old_size_for_status = team[person][status];
			if (status != TaskStatus::DONE)
				new_size_for_status = task_count >= old_size_for_status ? 0 : old_size_for_status - task_count;
			else
				new_size_for_status = old_size_for_status;

			remainder = min(old_size_for_status, task_count);
			task_count -= remainder;

			team_untouched[status] = new_size_for_status;

			team[person][status] = team_untouched[status] + team_updated[status];
			team_untouched[TaskStatus::DONE] = 0;

			if (team_untouched[status] != 0)
				team_untouched_cleared[status] = team_untouched[status];
			if (team_updated[status] != 0)
				team_updated_cleared[status] = team_updated[status];

			//update_status(status);
		}

		return make_tuple(team_updated_cleared, team_untouched_cleared);
	}

private:
	map<string, TasksInfo> team;



};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь


int main() {
	TeamTasks tasks;
	TasksInfo updated_tasks, untouched_tasks;

	for (int i = 0 ; i < 5; ++i)
		tasks.AddNewTask("Alice");
	//PrintTasksInfo(updated_tasks);
	//PrintTasksInfo(untouched_tasks);

	cout << "=====" << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
	PrintTasksInfo(updated_tasks);
	PrintTasksInfo(untouched_tasks);

	cout << "=====" << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
	PrintTasksInfo(updated_tasks);
	PrintTasksInfo(untouched_tasks);

	cout << "=====" << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
	PrintTasksInfo(updated_tasks);
	PrintTasksInfo(untouched_tasks);

	cout << "=====" << endl;

	for (int i = 0 ; i < 5; ++i)
		tasks.AddNewTask("Alice");

	cout << "=====" << endl;


	cout << "TASKS_INFO: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));


	cout << "=====" << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 2);
	PrintTasksInfo(updated_tasks);
	PrintTasksInfo(untouched_tasks);

	cout << "=====" << endl;

	//tasks.GetPersonTasksInfo("Alice");
	cout << "TASKS_INFO: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	cout << "=====" << endl;

	tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
	PrintTasksInfo(updated_tasks);
	PrintTasksInfo(untouched_tasks);

	cout << "=====" << endl;

	cout << "TASKS_INFO: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));



/*
	TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  //cout << "Ivan's tasks final: ";
  //PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
*/
  return 0;
}
