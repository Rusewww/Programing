cmake_minimum_required(VERSION 3.17)
# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../lab25/src)
include_directories(../lab26/src)

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run25 ../lab25/test/test.cpp ../lab25/src/list.cpp ../lab25/src/watch.cpp)
add_executable(Google_Tests_run26 ../lab26/test/test.cpp ../lab26/src/list.cpp ../lab26/src/watch.cpp)
target_link_libraries(Google_Tests_run25 gtest gtest_main)
target_link_libraries(Google_Tests_run26 gtest gtest_main)