#include "../../include/View/MenuAtendente.h"
#include "../../include/View/UtilidadesConsole.h"
#include <iostream>

void menuAtendente(Atendente& atendente) {
    int opcao = -1;

    while (true) {
        UtilidadesConsole::limparTela();
        std::cout << "===== MENU ATENDENTE =====\n";
        std::cout << "Bem-vindo, " << atendente.getNome() << "!\n";
        std::cout << "1 - Vender Ingresso\n";
        std::cout << "2 - Cancelar Venda\n";
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
                atendente.venderIngresso();
                break;
            case 2:
                atendente.cancelarVenda();
                break;
            case 0:
                std::cout << "Saindo do menu atendente...\n";
                UtilidadesConsole::pausar();
                return; // sai do menu e volta pro main
            default:
                std::cout << "Opção inválida!\n";
        }

        UtilidadesConsole::pausar();
    }
}
