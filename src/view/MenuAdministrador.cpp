#include "../../include/View/MenuAdministrador.h"
#include "../../include/View/UtilidadesConsole.h"
#include <iostream>

void menuAdministrador(Administrador& adm) {
    int opcao = -1;

    while (true) {
        UtilidadesConsole::limparTela();
        std::cout << "===== MENU ADMINISTRADOR =====\n";
        std::cout << "Bem-vindo, " << adm.getNome() << "!\n";
        std::cout << "1 - Cadastrar Filme\n";
        std::cout << "2 - Cadastrar Sala\n";
        std::cout << "3 - Cadastrar Sessão\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";

        if (!(std::cin >> opcao)) {
            UtilidadesConsole::limparBuffer();
            std::cout << "Entrada inválida! Digite apenas números.\n";
            UtilidadesConsole::pausar();
            continue;
        }

        UtilidadesConsole::limparBuffer(); // limpa o ENTER
        UtilidadesConsole::limparTela();

        switch (opcao) {
            case 1:
                adm.cadastrarFilme();
                break;
            case 2:
                adm.cadastrarSala();
                break;
            case 3:
                adm.cadastrarSessao();
                break;
            case 0:
                std::cout << "Saindo do menu administrador...\n";
                UtilidadesConsole::pausar();
                return; // sai do loop e volta pro main
            default:
                std::cout << "Opção inválida!\n";
        }

        UtilidadesConsole::pausar();
    }
}
