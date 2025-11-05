#ifndef CINEMA_MANAGEMENT_ATENDENTE_H
#define CINEMA_MANAGEMENT_ATENDENTE_H

#include "Funcionario.h"
#include <string>
#include <iostream>

class Atendente : public Funcionario {
public:
    // Construtor
    Atendente(int id, const std::string& nome, double salario, const std::string& usuario = "", const std::string& senha = "");

    // Metodo obrigatorio da classe herdada, ainda irei ajustar
    void executarTarefa() const override;

    // ainda irei "integrar" com as classe Ingresso quando for criada
    void venderIngresso();
    void cancelarVenda();
};


#endif //CINEMA_MANAGEMENT_ATENDENTE_H