#include "../../include/View/MenuAtendente.h"
#include <iostream>

void menuAtendente(Atendente& atendente) {
    int opcao = -1;

    while (true) {
        std::cout << "===== MENU ATENDENTE =====\n";
        std::cout << "Bem-vindo, " << atendente.getNome() << "!\n";
        std::cout << "1 - Vender Ingresso\n";
        std::cout << "2 - Cancelar Venda\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";

        if (!(std::cin >> opcao)) {
            std::cout << "Entrada inválida! Digite apenas números.\n";
            continue;
        }


        switch (opcao) {
            case 1:
                atendente.venderIngresso();
                break;
            case 2:
                atendente.cancelarVenda();
                break;
            case 0:
                std::cout << "Saindo do menu atendente...\n";
                return; // sai do menu e volta pro main
            default:
                std::cout << "Opção inválida!\n";
        }

    }
}
