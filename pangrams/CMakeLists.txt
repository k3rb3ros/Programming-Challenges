cmake_minimum_required (VERSION 2.6)

set (CMAKE_C_COMPILER "/usr/bin/clang")
project (Pangrams)
include (CheckIncludeFiles)

set (CMAKE_BUILD_TYPE Debug)

#compiler flags
set (CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 -Wall -Wextra -pedantic")
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

#CPP files to compile
set (proj_src
     pangrams.c
    )

add_executable (${PROJECT_NAME} ${proj_src})
