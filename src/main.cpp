#include <iostream>
#include "Todo.hpp"
#include <string>

using namespace std;

void main()
{
    cout << "Welcome to Todo List Manager!" << endl;
    cout << "Your todos will be saved to a file." << endl;
    cout << "You can add and remove todos as needed." << endl;
    int choice;
    Todo task;
    while (true)
    {
        cout << "\n1. Add Todo" << endl;
        cout << "2. Display Todos" << endl;
        cout << "3. Remove Todo" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();                                         // clear fail flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            continue;
        }

        cin.ignore();

        vector<TodoItem> todos;
        switch (choice)
        {
        case 1:
        {
            TodoItem todoitm;

            cout << "Enter todo title: ";
            cin >> todoitm.task;

            cout << "Enter due date (DD/MM/YYYY): ";
            string dateStr;
            cin >> dateStr;
            sscanf(dateStr.c_str(), "%d/%d/%d", &todoitm.endDate.day, &todoitm.endDate.month, &todoitm.endDate.year);

            task.addTodo(todoitm);
            break;
        }
        case 2:
            todos = task.getAllTodos();
            if (todos.empty())
            {
                cout << "No todos found!" << endl;
            }
            else
            {
                for (int i = 0; i < todos.size(); i++)
                {
                    cout << i + 1 << ". " << todos[i].task
                         << " (Due: " << todos[i].endDate.day << "/"
                         << todos[i].endDate.month << "/"
                         << todos[i].endDate.year << ")" << endl;
                }
            }
            break;
        case 3:
        {
            cout << "Enter the number of todo to remove: ";
            int index;
            cin >> index;
            TodoItem *todo = task.getTodo(index - 1);
            cout << "Removing todo: " << todo->task
                 << " (Due: " << todo->endDate.day << "/"
                 << todo->endDate.month << "/"
                 << todo->endDate.year << ")" << endl;
            task.removeTodo(index - 1);
            break;
        }
        case 4:
            cout << "Goodbye!" << endl;
            
            return;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
