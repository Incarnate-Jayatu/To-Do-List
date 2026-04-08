#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

vector<string> tasks;
vector<int> days, months, years;

void add_task();
void delete_task(int task_number);
void display_tasks();
bool validate_date(int day, int month, int year);
string user_choice(int choice);

string user_choice(int choice) {
    if (choice == 1) {
        add_task();
    } 
    else if (choice == 2) {
        if (tasks.empty()) {
            cout << "No tasks available.\n\n";
            return "";
        }
        display_tasks();
        int task_number;
        cout << "Enter task number to delete: ";
        cin >> task_number;
        delete_task(task_number);
    } 
    else if (choice == 3) {
        display_tasks();
    } 
    else if (choice == 4) {
        return "Exiting application. Goodbye!";
    } 
    else {
        cout << "Invalid choice!\n\n";
    }
    return "";
}
void delete_task(int task_number) {
    int index = task_number - 1;
    if (index >= 0 && index < tasks.size()) {
        cout << "Task '" << tasks[index] << "' deleted successfully!\n\n";
        tasks.erase(tasks.begin() + index);
        days.erase(days.begin() + index);
        months.erase(months.begin() + index);
        years.erase(years.begin() + index);
    } 
    else {
        cout << "Invalid task number!\n\n";
    }
}
void display_tasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n\n";
        return;
    }
    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i]
             << " - Deadline: "
             << (days[i] < 10 ? "0" : "") << days[i] << "-"
             << (months[i] < 10 ? "0" : "") << months[i] << "-"
             << years[i] << endl;
    }
    cout << endl;
}
void add_task() {
    string task_name;
    int day, month, year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter task name: ";
    getline(cin, task_name);
    cout << "Enter deadline:\n";
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    if (!validate_date(day, month, year)) {
        cout << "Invalid date! Task not added.\n\n";
        return;
    }
    tasks.push_back(task_name);
    days.push_back(day);
    months.push_back(month);
    years.push_back(year);
    cout << "Task added successfully!\n\n";
}
bool validate_date(int day, int month, int year) {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    int days_in_month;
    if (month == 2) {
        days_in_month = ((year % 400 == 0) || 
                        (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
    } 
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } 
    else {
        days_in_month = 31;
    }
    return day >= 1 && day <= days_in_month;
}
int main() {
    cout << "\nWelcome to the To-Do List Application!\n\n";
    while (true) {
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        string result = user_choice(choice);
        if (result == "Exiting application. Goodbye!") {
            cout << result << endl;
            break;
        }
    }
    return 0;
}
