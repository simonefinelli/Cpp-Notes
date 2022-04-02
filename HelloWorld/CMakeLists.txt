cmake_minimum_required(VERSION 3.21)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

add_executable(HelloWorld main.cpp)
