cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD 17)

project(Day04)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link test code with code we want to test and the GTest and pthread library
add_executable(test_day04_part1 test_day04_part1.cpp day04_functions.cpp bingo_board.cpp)
add_executable(day04_part1 day04_part1.cpp day04_functions.cpp bingo_board.cpp)

target_link_libraries(test_day04_part1 ${GTEST_LIBRARIES} pthread)
target_link_libraries(day04_part1)

