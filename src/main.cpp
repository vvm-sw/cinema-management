#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/RepositorioAdministrador.h"
#include "../include/RepositorioAtendente.h"
#include "../include/RepositorioFilmes.h"
#include <iostream>
#include <memory>

int main() {
    // Serve para permitir utilização de acentos no terminal
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    RepositorioAdministrador repoAdm("../data/administradores.csv");
    RepositorioAtendente repoAt("../data/atendentes.csv");

    int tipoLogin = -1;
    std::string usuario, senha;
    std::unique_ptr<Funcionario> funcionario; //

    while (true) {
        system("cls");
        std::cout << "===========================\n";
        std::cout << "   CINEMA MANAGEMENT\n";
        std::cout << "===========================\n";
        std::cout << "1 - Login como Administrador\n";
        std::cout << "2 - Login como Atendente\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin >> tipoLogin;

        if (tipoLogin == 0) break;

        std::cout << "Usuário: ";
        std::cin >> usuario;
        std::cout << "Senha: ";
        std::cin >> senha;

        if (tipoLogin == 1) {
            auto* adm = repoAdm.autenticar(usuario, senha);
            if (adm) funcionario.reset(adm);
        } else if (tipoLogin == 2) {
            auto* at = repoAt.autenticar(usuario, senha);
            if (at) funcionario.reset(at);
        }

        if (funcionario) {
            funcionario->executarTarefa();
            funcionario.reset();
        } else {
            std::cout << "Usuário ou senha incorretos!\n";
            std::cin.ignore();
            std::cin.get();
        }
    }

    std::cout << "Encerrando o sistema...\n";
    return 0;
}
