#include "../../include/Funcionario.h"

// Construtor
Funcionario::Funcionario(int id, const std::string& nome, const std::string& cargo, double salario)
    : id(id), nome(nome), cargo(cargo), salario(salario) {}

// Getters
int Funcionario::getId() const { return id; }
std::string Funcionario::getNome() const { return nome; }
std::string Funcionario::getCargo() const { return cargo; }
double Funcionario::getSalario() const { return salario; }

// Setters
void Funcionario::setNome(const std::string& novoNome) { nome = novoNome; }
void Funcionario::setCargo(const std::string& novoCargo) { cargo = novoCargo; }
void Funcionario::setSalario(double novoSalario) { salario = novoSalario; }

// Método comum
void Funcionario::exibirInfo() const {
    std::cout << "Funcionario: " << nome
              << " | Cargo: " << cargo
              << " | Salario: R$ " << salario << std::endl;
}