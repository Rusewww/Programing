cmake_minimum_required(VERSION 3.17)
project(RGZ)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
add_executable(RGZ src/controller.cpp src/list.cpp src/menu.cpp src/watch.cpp src/main.cpp)