cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_COMPILER "/usr/bin/clang++")
project (div_pairs)
include (CheckIncludeFiles)

set (CMAKE_BUILD_TYPE Debug)

#compiler flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

#CPP files to compile
set (proj_src
     divisible_sum_pairs.cpp
    )

add_executable (${PROJECT_NAME} ${proj_src})
