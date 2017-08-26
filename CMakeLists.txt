cmake_minimum_required(VERSION 3.7)
project(MonteCarloThreads)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Task.h TaskPoolManager.cpp MonteCarloTask.cpp)
add_executable(MonteCarloThreads ${SOURCE_FILES})