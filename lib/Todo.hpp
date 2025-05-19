#pragma once

#include <vector>
#include <unordered_set>
#include "TodoItem.hpp"
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;
class Todo
{
private:
    std::unordered_set<int> ids;
    std::vector<TodoItem> todos;
    std::string todoHistroyFile;
    std::string todoCompletedFile;
    std::string todoNotCompletedFile;

public:
    Todo()
    {

        if (!fs::exists("DB"))
        {
            fs::create_directories("DB");
        }
        std::string nano = std::to_string(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        this->todoCompletedFile = "DB/_todoCompletedFile_" + nano + ".txt";
        this->todoNotCompletedFile = "DB/_todoNotCompletedFile_" + nano + ".txt";
        this->todoHistroyFile = "DB/_todoHistroyFile_" + nano + ".txt";
    };
    bool addTodo(TodoItem &todo);
    bool removeTodo(const int id);
    std::vector<TodoItem> getAllTodos();
    TodoItem *getTodo(int id);
};
