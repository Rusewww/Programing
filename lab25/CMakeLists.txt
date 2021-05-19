cmake_minimum_required(VERSION 3.17)
project(lab25)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(Main25 src/main.cpp src/watch.cpp src/list.cpp)
add_executable(Test25 test/test.cpp src/watch.cpp src/list.cpp)