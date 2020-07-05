cmake_minimum_required(VERSION 3.16.3)
project (backend-tests)

include_directories(../include)

file(GLOB SOURCES "Main.cpp")

set(EXECUTABLE_NAME "run-tests")
add_executable(${EXECUTABLE_NAME} ${SOURCES})
