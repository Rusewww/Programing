cmake_minimum_required(VERSION 3.17)
project(lab29)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(lab29_main src/main.cpp src/watch.cpp src/watch.h src/list.hpp)