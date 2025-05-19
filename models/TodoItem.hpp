#pragma once

#include <string>
#include "Date.hpp"

struct TodoItem
{
    int id;
    std::string task;
    Date endDate;
    bool completed;
};