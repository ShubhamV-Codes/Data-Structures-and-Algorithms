#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Todo {
    vector<string> tasks;
    const string filename = "tasks.txt";

public:
    Todo() {
        loadTasks();
    }

    void loadTasks() {
        tasks.clear();
        ifstream fin(filename);
        string task;
        while (getline(fin, task)) {
            tasks.push_back(task);
        }
        fin.close();
    }

    void saveTasks() {
        ofstream fout(filename);
        for (string task : tasks) {
            fout << task << endl;
        }
        fout.close();
    }

    void addTask() {
        cout << "Enter new task: ";
        string task;
        cin.ignore();
        getline(cin, task);
        tasks.push_back(task);
        saveTasks();
        cout << "✅ Task added.\n";
    }

    void viewTasks() {
        cout << "\n📋 To-Do List:\n";
        if (tasks.empty()) {
            cout << "No tasks found.\n";
            return;
        }
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void deleteTask() {
        viewTasks();
        cout << "\nEnter task number to delete: ";
        int index;
        cin >> index;
        if (index < 1 || index > tasks.size()) {
            cout << "❌ Invalid task number.\n";
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        saveTasks();
        cout << "🗑️ Task deleted.\n";
    }

    void menu() {
        int choice;
        while (true) {
            cout << "\n===== TO-DO LIST MENU =====\n";
            cout << "1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n";
            cout << "Choose: ";
            cin >> choice;

            switch (choice) {
                case 1: addTask(); break;
                case 2: viewTasks(); break;
                case 3: deleteTask(); break;
                case 4: return;
                default: cout << "Invalid choice.\n";
            }
        }
    }
};

int main() {
    Todo t;
    t.menu();
    return 0;
}
