cmake_minimum_required(VERSION 3.17)
project(lab28)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(Main28 src/main.cpp src/list.cpp)