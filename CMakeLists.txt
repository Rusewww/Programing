cmake_minimum_required(VERSION 3.17)
project(Programing C)

set(CMAKE_C_STANDARD 11)

include_directories(lab11/task01/src)
include_directories(lab11/task02/src)
include_directories(lab11/task03/src)
include_directories(lab11/task04/src)
include_directories(lab12/src)

add_executable(Programing
        lab12/src/lib.c
        lab12/src/lib.h
        lab12/src/main.c)
