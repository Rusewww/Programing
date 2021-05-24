cmake_minimum_required(VERSION 3.17)
# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../lab25/src)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run ../lab25/test/test.cpp ../lab25/src/list.cpp ../lab25/src/watch.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run gtest D:/Programing/lab25/src)
target_link_libraries(Google_Tests_run gtest D:/Programing/lab25/test)