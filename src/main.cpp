
#include <iostream>
#include "../include/Cinema.h"
#include "../include/Sala.h"
#include "../include/RepositorioFilmes.h"
#include "../include/FilmeCLI.h"
#include "../include/Administrador.h"
#include "../include/Atendente.h"
#include "../include/RepositorioAtendente.h"
#include "../include/RepositorioAdministrador.h"

using namespace std;

// Função auxiliar para limpar a tela
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void menuAdministrador() {
    int opcao = -1;

    while (opcao != 0) {
        limparTela();

        std::cout << "=============================\n";
        std::cout << "     MENU ADMINISTRADOR\n";
        std::cout << "=============================\n";
        std::cout << "1 - Cadastrar Filme\n";
        std::cout << "2 - Cadastrar Sala\n";
        std::cout << "3 - Cadastrar Sessão\n";
        std::cout << "0 - Voltar\n";
        std::cout << "-----------------------------\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        limparTela();

        switch (opcao) {
            case 1:
                std::cout << "📽Função 'Cadastrar Filme' ainda não implementada.\n";
                break;
            case 2:
                std::cout << "Função 'Cadastrar Sala' ainda não implementada.\n";
                break;
            case 3:
                std::cout << "Função 'Cadastrar Sessão' ainda não implementada.\n";
                break;
            case 0:
                std::cout << "Voltando ao menu principal...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }

        if (opcao != 0) {
            std::cout << "\nPressione ENTER para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }
}

void menuAtendente() {
    int opcao = -1;

    while (opcao != 0) {
        limparTela();

        std::cout << "=============================\n";
        std::cout << "     💼 MENU ATENDENTE\n";
        std::cout << "=============================\n";
        std::cout << "1 - Vender Ingresso\n";
        std::cout << "2 - Cancelar Venda\n";
        std::cout << "0 - Voltar\n";
        std::cout << "-----------------------------\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        limparTela();

        switch (opcao) {
            case 1:
                std::cout << "Função 'Vender Ingresso' ainda não implementada.\n";
                break;
            case 2:
                std::cout << "Função 'Cancelar Venda' ainda não implementada.\n";
                break;
            case 0:
                std::cout << "Voltando ao menu principal...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }

        if (opcao != 0) {
            std::cout << "\nPressione ENTER para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }
}

int main () {
    RepositorioAdministrador repoAdm("../data/administradores.csv");
    RepositorioAtendente repoAt("../data/atendentes.csv");

    int opcao = -1;
    std::string usuario, senha;

    while (opcao != 0) {
        limparTela();
        std::cout << "===========================\n";
        std::cout << "   CINEMA MANAGEMENT\n";
        std::cout << "===========================\n";
        std::cout << "1 - Login como Administrador\n";
        std::cout << "2 - Login como Atendente\n";
        std::cout << "0 - Sair\n";
        std::cout << "---------------------------\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        if (opcao == 0) break;

        limparTela();
        std::cout << "Usuário: ";
        std::cin >> usuario;
        std::cout << "Senha: ";
        std::cin >> senha;

        if (opcao == 1) {
            auto* adm = repoAdm.autenticar(usuario, senha);
            if (adm) {
                std::cout << "Bem-vindo, " << adm->getNome() << "!\n";
                pausar();
                menuAdministrador();
            } else {
                std::cout << "Usuário ou senha incorretos.\n";
                pausar();
            }
        } else if (opcao == 2) {
            auto* at = repoAt.autenticar(usuario, senha);
            if (at) {
                std::cout << "Bem-vindo, " << at->getNome() << "!\n";
                pausar();
                menuAtendente();
            } else {
                std::cout << "Usuário ou senha incorretos.\n";
                pausar();
            }
        }
    }

    limparTela();
    std::cout << "👋 Encerrando o sistema...\n";
    return 0;

}
