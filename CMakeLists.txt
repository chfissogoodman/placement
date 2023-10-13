cmake_minimum_required(VERSION 3.26)
project(memorylist_c_f)

set(CMAKE_CXX_STANDARD 17)

add_executable(memorylist_c_f main.cpp
        Parser_for_memlist.cpp
        Parser_for_memlist.h
        Database.h)
