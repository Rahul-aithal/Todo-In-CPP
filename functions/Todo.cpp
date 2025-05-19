#pragma once

#include <string>
#include <iostream>
#include "Todo.hpp"
#include "Files.cpp"

bool Todo::addTodo( TodoItem &todo)
{
    int nano = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    todo.id = nano;
    auto [id, inserted] = this->ids.insert(todo.id);
    if (!inserted)
    {
        return false;
    }
    this->todos.push_back(todo);
    int isCompletedFirst = AppendTodoToFile(this->todoHistroyFile, todo);
    int isCompletedSecond = AppendTodoToFile(this->todoNotCompletedFile, todo);
    if (isCompletedFirst != 0 || isCompletedSecond != 0)
    {
        std::cout << "Error while Writing in file";
        return false;
    }

    return true;
}
bool Todo::removeTodo(const int id)
{

    size_t removed = this->ids.erase(id);
    if (removed > 0)
    {

        if (deleteTodoFile(this->todoNotCompletedFile, id) != 0)
        {
            std::cout << "Error while deleting from in file";
            return false;
        }
        return true;
    }
    return false;
}
std::vector<TodoItem> Todo::getAllTodos()
{
    return this->todos;
}
TodoItem *Todo::getTodo(int id)
{
    for (auto &todo : this->todos)
    {
        if (todo.id == id)
        {
            return &todo;
        }
    }
    return nullptr;
}