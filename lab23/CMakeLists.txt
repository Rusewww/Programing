cmake_minimum_required(VERSION 3.17)
project(lab23)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(Main src/main.cpp src/watch.cpp src/list.cpp)
add_executable(Test test/test.cpp src/watch.cpp src/list.cpp)