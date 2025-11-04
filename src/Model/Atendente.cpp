#include "../../include/Atendente.h"
#include "../../include/View/MenuAtendente.h"

// Construtor
Atendente::Atendente(int id, const std::string& nome, double salario, const std::string& usuario, const std::string& senha)
    : Funcionario(id, nome, "Atendente", salario, usuario, senha) {}

// Implementação dos métodos
void Atendente::executarTarefa() const {
    std::cout << "Bem-vindo, Atendente " << nome << "!\n";
    std::cout << "Acessando o painel de vendas...\n\n";
    menuAtendente(const_cast<Atendente&>(*this));
}

void Atendente::venderIngresso() {
    std::cout << "Método de venda de ingresso ainda não implementado."
              << std::endl;
}

void Atendente::cancelarVenda() {
    std::cout << "Método de cancelamento de venda ainda não implementado."
              << std::endl;
}