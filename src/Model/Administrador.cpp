#include "../../include/Administrador.h"
// Construtor chama o da classe base
Administrador::Administrador(int id, const std::string& nome, double salario)
    : Funcionario(id, nome, "Administrador", salario) {}

// Implementação do método obrigatório
void Administrador::executarTarefa() const {
    std::cout << "Administrador " << nome
              << " é responsável por cadastrar filmes, salas e sessões."
              << std::endl;
}

// Métodos-modelo (ainda sem lógica concreta)
void Administrador::cadastrarFilme() {
    std::cout << "Método de cadastrar filme ainda não implementado." << std::endl;
}

void Administrador::cadastrarSala() {
    std::cout << "Método de cadastrar sala ainda não implementado." << std::endl;
}

void Administrador::cadastrarSessao() {
    std::cout << "Método de cadastrar sessão ainda não implementado." << std::endl;
}