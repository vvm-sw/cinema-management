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
        src/Model/Funcionario.cpp
        src/Model/Administrador.cpp
        src/Model/Atendente.cpp
        src/Model/CinemaRepositorio.cpp
        src/Model/Sessao.cpp
        src/Model/RepositorioAtendente.cpp
        src/Model/RepositorioAdministrador.cpp
        src/view/MenuAdministrador.cpp
        src/view/MenuAtendente.cpp
        src/Model/RepositorioSalas.cpp
        src/Model/RepositorioSessoes.cpp
)

