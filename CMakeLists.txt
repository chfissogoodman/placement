cmake_minimum_required(VERSION 3.24)
project(placement)

set(CMAKE_CXX_STANDARD 17)

add_executable(placement main.cpp
        include/place.h
        include/place.h
        include/exporter.h
        include/database.h
        src/exporter.cpp
        src/parser.cpp
        src/place.cpp
        include/parser.h)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(parser src/parser.cpp)