#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "TodoItem.hpp"

std::string convertTodoToString(const TodoItem &todo)
{
    std::ostringstream ostring;
    ostring << todo.id << " " << todo.task << " [ "
            << todo.endDate.day << "-" << todo.endDate.month << "-" << todo.endDate.year << " ]";
    return ostring.str();
}

int AppendTodoToFile(const std::string filename, const TodoItem &todo)
{
    std::ofstream file(filename, std::ios::app);

    if (!file)
    {
        std::cerr << "Error opening file for writing\n";
        return 1;
    }

    std::string TodoValue = convertTodoToString(todo);
    if (todo.completed)
        file << TodoValue << " " << "Completed ✔️" << std::endl;
    else
        file << TodoValue << std::endl;

    file.close();
    return 0;
}

int deleteTodoFile(const std::string filename, const int id)
{
    std::ifstream file(filename);
    std::string tempFileName = "temp" + filename + ".txt";
    std::ofstream tempFile(tempFileName);

    if (!file || !tempFile)
    {
        std::cerr << "Error opening file for writing\n";
        return 1;
    }

    std::string line;
    bool found = false;
    while (std::getline(file, line))
    {
        std::istringstream istream(line);
        int lineId;
        istream >> lineId;

        if (lineId == id)
        {
            found = true;
            continue;
        }
        tempFile << line << "\n";
    }
    std::remove(filename.c_str());
    std::rename(tempFileName.c_str(), filename.c_str());

    return found ? 0 : 1;
}