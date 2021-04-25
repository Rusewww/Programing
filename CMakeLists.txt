cmake_minimum_required(VERSION 3.17)
project(Programing C)

set(CMAKE_C_STANDARD 11)

add_executable(Programing lab22/src/main.c lab22/src/list.c lab22/src/data.c lab22/src/data.h lab22/src/list.h)
