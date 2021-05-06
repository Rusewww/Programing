cmake_minimum_required(VERSION 3.17)
project(lab23)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(lab23_main src/main.cpp src/watch.cpp src/watch.h src/list.cpp src/list.h)
add_executable(lab23_test test/test.cpp src/watch.cpp src/watch.cpp)