#include "../../include/View/MenuAdministrador.h"
#include "../../include/View/UtilidadesConsole.h"
#include "../../include/RepositorioFilmes.h"
#include <iostream>
#include <limits>

void menuAdministrador(Administrador& adm) {
    int opcao = -1;

    RepositorioFilmes repoFilmes("../data/filmes.csv");

    while (opcao != 0) {
        UtilidadesConsole::limparTela();
        std::cout << "===== MENU ADMINISTRADOR =====\n";
        std::cout << "Bem-vindo, " << adm.getNome() << "!\n";
        std::cout << "1 - Gerenciar Filmes\n";
        std::cout << "2 - Gerenciar Salas\n";
        std::cout << "3 - Gerenciar Sessões\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";

        if (!(std::cin >> opcao)) {
            UtilidadesConsole::limparBuffer();
            std::cout << "Entrada inválida!\n";
            UtilidadesConsole::pausar();
            continue;
        }

        UtilidadesConsole::limparBuffer();
        UtilidadesConsole::limparTela();

        switch (opcao) {
            case 1: {
                int opcaoFilmes = -1;
                while (opcaoFilmes != 0) {
                    UtilidadesConsole::limparTela();
                    std::cout << "===== GERENCIAR FILMES =====\n";
                    std::cout << "1 - Listar todos os filmes\n";
                    std::cout << "2 - Cadastrar novo filme\n";
                    std::cout << "3 - Atualizar filme existente\n";
                    std::cout << "4 - Remover filme\n";
                    std::cout << "0 - Voltar\n";
                    std::cout << "Escolha: ";

                    if (!(std::cin >> opcaoFilmes)) {
                        UtilidadesConsole::limparBuffer();
                        std::cout << "Entrada inválida!\n";
                        UtilidadesConsole::pausar();
                        continue;
                    }

                    UtilidadesConsole::limparBuffer();
                    UtilidadesConsole::limparTela();

                    switch (opcaoFilmes) {
                        case 1: {
                            // LISTAR FILMES
                            auto filmes = repoFilmes.listarFilmes();
                            if (filmes.empty()) {
                                std::cout << "Nenhum filme cadastrado.\n";
                            } else {
                                std::cout << "===== LISTA DE FILMES =====\n";
                                for (const auto& f : filmes) {
                                    std::cout << "ID: " << f.getId() << "\n"
                                              << "Título: " << f.getTitulo() << "\n"
                                              << "Gênero: " << f.getGenero() << "\n"
                                              << "Descrição: " << f.getDescricao() << "\n"
                                              << "---------------------------\n";
                                }
                            }
                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 2: {
                            // CADASTRAR NOVO FILME
                            std::string titulo, genero, descricao;

                            std::cout << "Título: ";
                            std::getline(std::cin, titulo);
                            std::cout << "Gênero: ";
                            std::getline(std::cin, genero);
                            std::cout << "Descrição: ";
                            std::getline(std::cin, descricao);

                            repoFilmes.adicionarFilme(titulo, genero, descricao);
                            std::cout << "Filme cadastrado com sucesso!\n";
                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 3: {
                            // ATUALIZAR FILME EXISTENTE
                            int id;
                            std::string titulo, genero, descricao;

                            std::cout << "Informe o ID do filme a ser atualizado: ";
                            std::cin >> id;
                            UtilidadesConsole::limparBuffer();

                            Filme* filme = repoFilmes.buscarPorId(id);
                            if (!filme) {
                                std::cout << "Filme com ID " << id << " não encontrado.\n";
                            } else {
                                std::cout << "Novo título (atual: " << filme->getTitulo() << "): ";
                                std::getline(std::cin, titulo);
                                std::cout << "Novo gênero (atual: " << filme->getGenero() << "): ";
                                std::getline(std::cin, genero);
                                std::cout << "Nova descrição (atual: " << filme->getDescricao() << "): ";
                                std::getline(std::cin, descricao);

                                // Mantém valores antigos se o usuário deixar em branco
                                if (titulo.empty()) titulo = filme->getTitulo();
                                if (genero.empty()) genero = filme->getGenero();
                                if (descricao.empty()) descricao = filme->getDescricao();

                                Filme atualizado(id, titulo, genero, descricao);
                                repoFilmes.atualizarFilme(id, atualizado);
                            }
                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 4: {
                            // REMOVER FILME
                            int id;
                            std::cout << "Informe o ID do filme a ser removido: ";
                            std::cin >> id;
                            UtilidadesConsole::limparBuffer();

                            if (repoFilmes.removerFilme(id)) {
                                std::cout << "Filme removido com sucesso!\n";
                            } else {
                                std::cout << "Filme com ID " << id << " não encontrado.\n";
                            }

                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 0:
                            break;

                        default:
                            std::cout << "Opção inválida!\n";
                            UtilidadesConsole::pausar();
                    }
                }
                break;
            }

            case 2:
                adm.cadastrarSala();
                UtilidadesConsole::pausar();
                break;

            case 3:
                adm.cadastrarSessao();
                UtilidadesConsole::pausar();
                break;

            case 0:
                std::cout << "Saindo do menu administrador...\n";
                UtilidadesConsole::pausar();
                break;

            default:
                std::cout << "Opção inválida!\n";
                UtilidadesConsole::pausar();
        }
    }
}
