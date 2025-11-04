#include "../../include/Administrador.h"
#include "../../include/View/MenuAdministrador.h"


// Construtor
Administrador::Administrador(int id, const std::string& nome, double salario, const std::string& usuario, const std::string& senha)
    : Funcionario(id, nome, "Administrador", salario, usuario, senha) {}

// Implementação dos Métodos
void Administrador::executarTarefa() const {
    std::cout << "Bem-vindo, Administrador " << nome << "!\n";
    std::cout << "Acessando o painel de gerenciamento...\n\n";
    menuAdministrador(const_cast<Administrador&>(*this));
}

void Administrador::cadastrarFilme() {
    std::cout << "Método de cadastrar filme ainda não implementado." << std::endl;
}

void Administrador::cadastrarSala() {
    std::cout << "Método de cadastrar sala ainda não implementado." << std::endl;
}

void Administrador::cadastrarSessao() {
    std::cout << "Método de cadastrar sessão ainda não implementado." << std::endl;
}