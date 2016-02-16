#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(myproject)

set(CMAKE_BUILD_TYPE Debug)

set(TEST_NAME "tests")
add_executable(${TEST_NAME}
    BoundedTest.cpp
    PtrTest.cpp
    catch.hpp
    catchMain.cpp
    ../BoundedQueue.h
)


set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wall -Wextra -Wno-unused -pedantic")

set(EXECUTABLE_NAME tests)
# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
