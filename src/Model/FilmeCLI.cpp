#include "FilmeCLI.h"
#include "Filme.h"
#include <iostream>
#include <limits>

//limpa o buffer de entrada (evitando loop infinito em entradas invalidas)
static void limparEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//exibição do menu de filmes, permitindo interagir com o repositório
void runFilmeMenu(RepositorioFilmes& repo) {
    int opcao = 0;
    do { //menu principal
        std::cout << "\n=== Menu Filmes ===\n";
        std::cout << "1 - Adicionar filme\n";
        std::cout << "2 - Listar filmes\n";
        std::cout << "3 - Remover filme por ID\n";
        std::cout << "4 - Voltar\n";
        std::cout << "Escolha: ";

        //verifica se a entrada é valida
        if (!(std::cin >> opcao)) {
            std::cout << "Entrada invalida\n";
            limparEntrada();
            continue; //volta ao início do loop
        }
        std::cin.ignore();

        if (opcao == 1) {
            std::string titulo, genero, descricao;

            //vai coletar os dados do usuario
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Genero: ";
            std::getline(std::cin, genero);
            std::cout << "Descricao: ";
            std::getline(std::cin, descricao);

            //vai adicionar ao repositório e salva no arquivo
            repo.adicionar(Filme(titulo, genero, descricao));
            repo.salvar();

            std::cout << "Filme adicionado e salvo.\n";
        }

        //condicao para listar filmes
        else if (opcao == 2) {
            auto filmes = repo.listar();

            if (filmes.empty()) {
                std::cout << "Nenhum filme cadastrado.\n";
            }

            else {
                for (const auto& f : filmes) {
                    f.exibir();
                    std::cout << "-----------------\n";
                }
            }
        }

        //condicao para remover filmes
        else if (opcao == 3) {
            std::cout << "Digite o ID do filme para remover: ";
            int id;

            if (!(std::cin >> id)) {
                std::cout << "ID invalido\n";
                limparEntrada();
            }

            else {
                if (repo.removerPorId(id)) {
                    repo.salvar();
                    std::cout << "Filme removido.\n";
                }

                else {
                    std::cout << "Filme com ID " << id << " nao encontrado.\n";
                }
            }
        }
    } while (opcao != 4);
}
