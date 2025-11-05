#ifndef CINEMA_MANAGEMENT_ADMINISTRADOR_H
#define CINEMA_MANAGEMENT_ADMINISTRADOR_H

#include "Funcionario.h"
#include <string>
#include <iostream>

class Administrador : public Funcionario {
public:
    // Construtor
    Administrador(int id, const std::string& nome, double salario, const std::string& usuario = "", const std::string& senha = "");

    // Metodo obrigatorio da classe base
    void executarTarefa() const override;

    // Metódos que o adm será responsável
    // Crud de filmes
    void cadastrarFilme();
    void listarFilmes();
    void atualizarFilme();
    void removerFilme();

    // Crud de salas
    void cadastrarSala();
    void listarSalas();
    void atualizarSala();
    void removerSala();

    //Crud de sessões
    void cadastrarSessao();
};
#endif //CINEMA_MANAGEMENT_ADMINISTRADOR_H