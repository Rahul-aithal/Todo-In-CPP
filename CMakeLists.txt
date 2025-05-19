cmake_minimum_required(VERSION 4.0)

project(TodoList VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(TodoList src/main.cpp)

add_subdirectory(lib)
add_subdirectory(models)
add_subdirectory(functions)

target_include_directories(TodoList PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/models
    ${CMAKE_CURRENT_SOURCE_DIR}/functions
)

target_link_libraries(TodoList PRIVATE
    TodoLib
    Date
    TodoItem
    Files
)