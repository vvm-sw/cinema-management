cmake_minimum_required(VERSION 4.0)
project(cinema_management)

set(CMAKE_CXX_STANDARD 14)

include_directories("include")

add_executable(cinema_management
        src/Model/Cinema.cpp
        src/Model/Sala.cpp
        src/main.cpp
        include/Filme.h
        src/Model/Filme.cpp
        include/RepositorioFilmes.h
        src/Model/RepositorioFilmes.cpp
        include/FilmeCLI.h
        src/Model/FilmeCLI.cpp)
