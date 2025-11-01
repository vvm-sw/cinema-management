cmake_minimum_required(VERSION 4.0)
project(cinema_management)

set(CMAKE_CXX_STANDARD 14)

include_directories("include")

add_executable(cinema_management
        src/Model/Cinema.cpp
        src/Model/Sala.cpp
        src/main.cpp
        src/Model/Filme.cpp
        src/Model/RepositorioFilmes.cpp
        src/Model/FilmeCLI.cpp
        src/Model/Funcionario.cpp
        src/Model/Administrador.cpp
        src/Model/Atendente.cpp)

#find_package(libpqxx REQUIRED)
#add_subdirectory(deps/libpqxx build-pqxx)
#target_link_libraries(cinema_management PRIVATE pqxx)
