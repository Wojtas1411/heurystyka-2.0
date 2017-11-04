cmake_minimum_required(VERSION 3.8)
project(heurystyka_2_0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp utilities.h utilities.cpp w_lib.h w_lib.cpp)
add_executable(heurystyka_2_0 ${SOURCE_FILES})