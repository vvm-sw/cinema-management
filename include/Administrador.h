#ifndef CINEMA_MANAGEMENT_ADMINISTRADOR_H
#define CINEMA_MANAGEMENT_ADMINISTRADOR_H

#include "Funcionario.h"
#include <string>
#include <iostream>

class Administrador : public Funcionario {
public:
    // Construtor
    Administrador(int id, const std::string& nome, double salario);

    // Metodo obrigatorio da classe base, ainda irei ajustar
    void executarTarefa() const override;

    // Metódos que o adm será responsável, ainda irei "integrar" com as classes reais
    void cadastrarFilme();
    void cadastrarSala();
    void cadastrarSessao();
};
#endif //CINEMA_MANAGEMENT_ADMINISTRADOR_H