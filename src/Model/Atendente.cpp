#include "../../include/Atendente.h"
// Construtor
Atendente::Atendente(int id, const std::string& nome, double salario, const std::string& usuario, const std::string& senha)
    : Funcionario(id, nome, "Atendente", salario, usuario, senha) {}

// Implementação dos métodos
void Atendente::executarTarefa() const {
    std::cout << "Atendente " << nome
              << " é responsável por realizar e cancelar vendas de ingressos."
              << std::endl;
}

void Atendente::venderIngresso() {
    std::cout << "Método de venda de ingresso ainda não implementado."
              << std::endl;
}

void Atendente::cancelarVenda() {
    std::cout << "Método de cancelamento de venda ainda não implementado."
              << std::endl;
}