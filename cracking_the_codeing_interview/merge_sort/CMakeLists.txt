cmake_minimum_required (VERSION 2.6)

set (CMAKE_C_COMPILER "/usr/bin/clang")
set (CMAKE_CXX_COMPILER "/usr/bin/clang++")

set (Prob_Name "merge_sort")

project (${Prob_Name})
include (CheckIncludeFiles)

set (CMAKE_BUILD_TYPE Debug)

#compiler flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra -pedantic")
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

#CPP files to compile
set (proj_src
     ${Prob_Name}.c
    )

add_executable (${PROJECT_NAME} ${proj_src})
target_link_libraries (${PROJECT_NAME} m)
