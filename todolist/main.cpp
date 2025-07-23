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

public:
    //Constructor
    Task(string t, string desc = "", Priority p = MEDIUM, string due = "") 
        : id(nextId++), title(t), description(desc), status(PENDING), 
          priority(p), dueDate(due) {}
    
    //Getters
    int getId() const { return id; }
    string getTitle() const {return title;}
    Status getStatus() const { return status; }
    Priority getPriority() const { return priority; }
    string getDue() const { return dueDate; }

    //Setters
    void setTitle(string title) {this->title =  title;}
    void setDesc(string desc) { description = desc; }
    void setPrio(Priority p) { priority = p; }
    void markComplete() { this->status = COMPLETED; }

    //Display task specific info
    void display() const {
        cout << "[" << id << "] " << title;
        cout << " (" << (status == COMPLETED ? "Complete" : "incomplete") << ")";
        if (priority == HIGH) cout << " [HIGH]";
        cout << endl;
    }

};

int Task::nextId = 1;

class TaskManager {
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

void displayMenu(){
        cout << "----- WELCOME TO TO-DO LIST -----" << endl;
        cout << "----- WELCOME TO TO-DO LIST -----" << endl;
        cout << "addTask(name, desc)         : Add a new task with description." << endl;
        cout << "showTask(number)            : Show a task by its number." << endl;
        cout << "showAllTasks()              : List all tasks." << endl;
        cout << "showDesc(name)              : Show the description of a task." << endl;
        cout << "completedTask(name)         : Shows all completed tasks (name is unused)." << endl;
        cout << "incompleteTask(name)        : Misleading - currently marks task as complete." << endl;
    }

int main()
{
    TaskManager tm;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To ignore newline left by cin

        switch (choice) {
            case 1: {
                string name, desc;
                cout << "Enter task name: ";
                getline(cin, name);
                cout << "Enter task description: ";
                getline(cin, desc);
                tm.addTask(name, desc);
                break;
            }
            case 2: {
                int num;
                cout << "Enter task number: ";
                cin >> num;
                tm.showTask(num);
                break;
            }
            case 3:
                tm.showAllTasks();
                break;
            case 4: {
                string name;
                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, name);
                tm.showDesc(name);
                break;
            }
            case 5: {
                string name, newDesc;
                cout << "Enter task name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new description: ";
                getline(cin, newDesc);
                tm.editDesc(name, newDesc);
                break;
            }
            case 6: {
                string name;
                cout << "Enter task name to mark complete: ";
                cin.ignore();
                getline(cin, name);
                tm.completeTask(name);
                break;
            }
            case 7: {
                tm.completedTask("");
                break;
            }
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
