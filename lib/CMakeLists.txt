add_library(TodoLib ../functions/Todo.cpp Todo.hpp)

target_include_directories(TodoLib PUBLIC ${CMAKE_SOURCE_DIR}/models
      ${CMAKE_SOURCE_DIR}/lib
)