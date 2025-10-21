cmake_minimum_required(VERSION 4.0)
project(cinema_management)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/Model)

add_executable(cinema_management
        src/Model/cinema.cpp
        src/Model/cinema.h
        src/Model/Sala.cpp
        src/Model/Sala.h
        src/main.cpp)
