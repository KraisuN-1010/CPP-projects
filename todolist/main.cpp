#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
using namespace std;


enum Priority {LOW, MEDIUM, HIGH};
enum Status {PENDING, COMPLETED};

class Task {
    static int nextId;
    int id;
    string title;
    string description;
    Status status;
    Priority priority;
    string dueDate;


    //Constructor
    Task(string t, string desc = "", Priority p = MEDIUM, string due = "") 
        : id(nextId++), title(t), description(desc), status(PENDING), 
          priority(p), dueDate(due) {}
    
    //Getter
    
    
};

class Task {
private:
    int numOfTasks = 0;           // Keeps track of total tasks
    map<int, string> taskList;    // Maps task number to task name
    map<string, string> taskDesc; // Maps task name to its description
    map<string, bool> taskCompletion;

public:
    // Adds a new task with its description
    void addTask(const string &taskName, const string &description)
    {
        if (taskName.empty() || description.empty())
        {
            cout << "Task name and description cannot be empty!" << endl;
            return;
        }
        taskCompletion[taskName] = false;
        taskDesc[taskName] = description;
        taskList[++numOfTasks] = taskName;
    }

    // Displays a specific task by its number
    void showTask(int num)
    {
        if (taskList.find(num) == taskList.end())
        {
            cout << "Task number " << num << " is invalid" << endl;
            return;
        }
        cout << "Task is: " << taskList[num] << endl;
    }

    // Displays all tasks with their numbers
    void showAllTasks()
    {
        if (taskList.empty())
        {
            cout << "No tasks available!" << endl;
            return;
        }
        cout << "All Tasks:" << endl;
        for (auto it = taskList.begin(); it != taskList.end(); ++it)
        {
            cout << it->first << ". " << it->second << endl;
        }
    }

    // Shows description of a specific task
    void showDesc(const string &taskName)
    {
        if (taskDesc.find(taskName) == taskDesc.end())
        {
            cout << "Task not found!" << endl;
            return;
        }
        cout << "Description: " << taskDesc[taskName] << endl;
    }

    // Edit a specific task either by number or name

    void editDesc(string taskName, string newDesc)
    {

        taskDesc[taskName] = newDesc;
    }

    void editDesc(int num, string newDesc)
    {
        taskDesc[taskList[num]] = newDesc;
    }
    void completeTask(string taskName)
    {
        taskCompletion[taskName] = true;
    }
    void completedTask(string taskName)
    {
        for (auto t : taskCompletion)
        {
            if (t.second)
            {
                cout << "i hope everything is fine after this";
            }
        }
    }
    void incompleteTask(string taskName)
    {
        taskCompletion[taskName] = true;
    }
};

int main()
{
    Task task;
    cout << "----- WELCOME TO TO-DO LIST -----" << endl;
    cout << "addTask(name, desc)         : Add a new task with description." << endl;
    cout << "showTask(number)            : Show a task by its number." << endl;
    cout << "showAllTasks()              : List all tasks." << endl;
    cout << "showDesc(name)              : Show the description of a task." << endl;
    cout << "completedTask(name)         : Shows all completed tasks (name is unused)." << endl;
    cout << "incompleteTask(name)        : Misleading - currently marks task as complete." << endl;

    return 0;
}