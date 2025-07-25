#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
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
    vector<Task> tasks;

public:
    // Adds a new task with its description
    void addTask(Task t)
    {
        tasks.push_back(t);
    }

    // Displays a specific task by its number
    void showTask(int num)
    {
        if (num < 1 || num > tasks.size())
        {
            cout << "Task number " << num << " is invalid" << endl;
            return;
        }
        tasks[num - 1].display();
    }

    // Displays all tasks with their numbers
    void showAllTasks()
    {
        if (tasks.empty())
        {
            cout << "No tasks available!" << endl;
            return;
        }
        cout << "All Tasks:" << endl;
        for (auto task : tasks)
        {
            task.display();
        }
    }

    void completedTask() {
        for (auto task : tasks) {
            Status taskStatus = task.getStatus();
            if (taskStatus == COMPLETED) {
                task.display();
            }
        }
    }
    void incompleteTask() {
         for (auto task : tasks) {
            Status taskStatus = task.getStatus();
            if (taskStatus == PENDING) {
                task.display();
            }
        }
    }

   void deleteTask(int id) {
        auto it = remove_if(tasks.begin(), tasks.end(),
            [id](const Task& task) { return task.getId() == id; });
        
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "Task " << id << " deleted successfully." << endl;
        } else {
            cout << "Task " << id << " not found." << endl;
        }
    }

    void showStats() {
        int totalTasks = 0;
        int completedTasks = 0;
        for(auto task : tasks) {
            totalTasks++;
            if (task.getStatus() == COMPLETED) {
                completedTasks++;
            }
        }

        cout << "Total tasks: " << totalTasks <<  "\n Pending tasks: " << totalTasks - completedTasks << endl;
    }
    void markCompleted(int id) {  
        if (id > tasks.size() || id < 1) {
            cout << "Invalid id entered" << endl;
            return;
        }
        tasks[id - 1].markComplete(); 
    }

    
};

void displayMenu(){
    cout << "----- WELCOME TO TO-DO LIST -----" << endl;
    cout << "addTask(name, desc)[enter 1]      : Add a new task with description." << endl;
    cout << "showTask(number)  [enter 2]        : Show a task by its number." << endl;
    cout << "showAllTasks()  [enter 3]          : List all tasks." << endl;
    cout << "markComplete() [enter 4]           : Mark a task as completed" << endl;
    cout << "showStats()    [enter 5]    : show stats of todolist." << endl;
    cout << "completedTask() [enter 6]       : Shows all completed tasks" << endl;
    cout << "incompleteTask() [enter 7]       : Shows incomplete tasks" << endl;
    cout << "enter 8 to exit the code"<< endl;
}

int main()
{
    TaskManager taskManage;
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
                cout << "Enter 1 for high priority and 0 for low priority: ";
                int prioDecide;
                cin >> prioDecide;
                cin.ignore();
                cout << "Enter due date: ";
                string dueDate;
                getline(cin, dueDate);
                if (prioDecide) {
                    Task task = Task(name, desc, Priority::HIGH,dueDate);
                    taskManage.addTask(task);
                }
                else {
                    Task task = Task(name, desc, Priority::LOW,dueDate);
                    taskManage.addTask(task);
                }
                
                break;
            }
            case 2: {
                int num;
                cout << "Enter task ID: ";
                cin >> num;
                taskManage.showTask(num);
                break;
            }
            case 3:
                taskManage.showAllTasks();
                break;
            case 4: {
                int id;
                cout << "Enter task ID: ";
                cin >> id;
                taskManage.markCompleted(id);
                break;
            }
            case 5: {
                taskManage.showStats();
                break;
            }
            case 6: {
                taskManage.completedTask();
                break;
            }
            case 7: {
                taskManage.incompleteTask();
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
