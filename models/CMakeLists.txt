add_library(Date INTERFACE)
add_library(TodoItem INTERFACE)
target_include_directories(Date INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(TodoItem INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})