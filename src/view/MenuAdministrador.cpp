#include "../../include/View/MenuAdministrador.h"
#include <iostream>

void menuAdministrador() {
    std::cout << "===== MENU ADMINISTRADOR =====\n";
    std::cout << "1 - Gerenciar Filmes\n";
    std::cout << "2 - Gerenciar Salas\n";
    std::cout << "3 - Gerenciar Sessões\n";
    std::cout << "0 - Sair\n";
    std::cout << "Escolha: ";
}

void menuGerenciarFilmes() {
    std::cout << "===== GERENCIAR FILMES =====\n";
    std::cout << "1 - Listar todos os filmes\n";
    std::cout << "2 - Cadastrar novo filme\n";
    std::cout << "3 - Atualizar filme existente\n";
    std::cout << "4 - Remover filme\n";
    std::cout << "0 - Voltar\n";
    std::cout << "Escolha: ";
}

void menuGerenciarSalas() {
    std::cout << "===== GERENCIAR SALAS =====\n";
    std::cout << "1 - Listar todas as salas\n";
    std::cout << "2 - Cadastrar nova sala\n";
    std::cout << "3 - Atualizar sala existente\n";
    std::cout << "4 - Remover sala\n";
    std::cout << "0 - Voltar\n";
    std::cout << "Escolha: ";
}

void menuGerenciarSessoes() {
    std::cout << "===== GERENCIAR SESSÕES =====\n";
    std::cout << "1 - Listar todas as sessões\n";
    std::cout << "2 - Cadastrar nova sessão\n";
    std::cout << "3 - Atualizar sessão existente\n";
    std::cout << "4 - Remover sessão\n";
    std::cout << "0 - Voltar\n";
    std::cout << "Escolha: ";
}

