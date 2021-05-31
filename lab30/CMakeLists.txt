cmake_minimum_required(VERSION 3.17)
project(lab30)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(Main30 src/main.cpp src/watch.cpp src/list.cpp)