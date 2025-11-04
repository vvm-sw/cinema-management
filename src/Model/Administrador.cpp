#include "../../include/Administrador.h"
#include "../../include/View/MenuAdministrador.h"
#include "../../include/RepositorioFilmes.h"
#include <limits>

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
    std::string titulo, genero, descricao;

    std::cout << "===== CADASTRO DE FILME =====\n";

    std::cout << "Título: ";
    std::getline(std::cin, titulo);

    std::cout << "Gênero: ";
    std::getline(std::cin, genero);

    std::cout << "Descrição: ";
    std::getline(std::cin, descricao);

    // Cria o repositório e adiciona o novo filme
    RepositorioFilmes repo("../data/filmes.csv");
    repo.adicionarFilme(titulo, genero, descricao);

    std::cout << "\nFilme cadastrado com sucesso!\n";
}

void Administrador::cadastrarSala() {
    std::cout << "Método de cadastrar sala ainda não implementado." << std::endl;
}

void Administrador::cadastrarSessao() {
    std::cout << "Método de cadastrar sessão ainda não implementado." << std::endl;
}