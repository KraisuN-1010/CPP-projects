#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

class Task {
private:
    int numOfTasks = 0;                  // Keeps track of total tasks
    map<int, string> taskList;           // Maps task number to task name
    map<string, string> taskDesc;        // Maps task name to its description
    map<string, bool> taskCompletion;

public:
    // Adds a new task with its description
    void addTask(const string& taskName, const string& description) {
        if (taskName.empty() || description.empty()) {
            cout << "Task name and description cannot be empty!" << endl;
            return;
        }
        taskCompletion[taskName] = false;
        taskDesc[taskName] = description;
        taskList[++numOfTasks] = taskName;
    }

    // Displays a specific task by its number
    void showTask(int num) {
        if (taskList.find(num) == taskList.end()) {
            cout << "Task number " << num << " is invalid" << endl;
            return;
        }
        cout << "Task is: " << taskList[num] << endl;
    }

    // Displays all tasks with their numbers
    void showAllTasks() {
        if (taskList.empty()) {
            cout << "No tasks available!" << endl;
            return;
        }
        cout << "All Tasks:" << endl;
        for (auto it = taskList.begin(); it != taskList.end(); ++it) {
            cout << it->first << ". " << it->second << endl;
        }
    }
    
    // Shows description of a specific task
    void showDesc(const string& taskName) {
        if (taskDesc.find(taskName) == taskDesc.end()) {
            cout << "Task not found!" << endl;
            return;
        }
        cout << "Description: " << taskDesc[taskName] << endl;
    }

    //Edit a specific task either by number or name

    void editDesc(string taskName, string newDesc){

        taskDesc[taskName] = newDesc;
    }

    void editDesc(int num, string newDesc) {
        taskDesc[taskList[num]] = newDesc;
    }
    void completeTask(string taskName ){
        taskCompletion[taskName] = true;
    }
     void completedTask(string taskName ){
       for(auto t : taskCompletion){
        if (t.second )
        {
            /* code */
        }
        
       }
    }
     void incompleteTask(string taskName ){
        taskCompletion[taskName] = true;
    }
};

int main() {
    Task task;
    // Adding sample tasks
    task.addTask("Complete report", "Finish quarterly report by Friday");
    task.addTask("Team meeting", "Attend team sync at 2 PM");
    task.addTask("Code review", "Review PR #123");
    task.addTask("Test cases", "Write unit tests for new features");

    // Displaying task information
    task.showDesc("Complete report");
    task.showDesc("Team meeting");
    cout << "after" << endl;
    task.editDesc("Test cases","hello"); 
    task.showDesc("Test cases");

    cout << "after" << endl;
    task.editDesc(4,"helo"); 
    task.showDesc("Test cases");

    cout << "for task completetion enter task name";
    string name;
    getline(cin,name);
    task.completeTask(name);

    return 0;
}