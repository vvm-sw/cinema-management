#include "../../include/View/MenuAdministrador.h"
#include "../../include/View/UtilidadesConsole.h"
#include "../../include/RepositorioFilmes.h"
#include "../../include/RepositorioSalas.h"
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
            // Filmes
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

            // Salas
            case 2: {
                int opcaoSala = -1;
                RepositorioSalas repoSalas("../data/salas.csv");

                while (opcaoSala != 0) {
                    UtilidadesConsole::limparTela();
                    std::cout << "===== GERENCIAR SALAS =====\n";
                    std::cout << "1 - Listar todas as salas\n";
                    std::cout << "2 - Cadastrar nova sala\n";
                    std::cout << "3 - Atualizar sala existente\n";
                    std::cout << "4 - Remover sala\n";
                    std::cout << "0 - Voltar\n";
                    std::cout << "Escolha: ";

                    if (!(std::cin >> opcaoSala)) {
                        UtilidadesConsole::limparBuffer();
                        std::cout << "Entrada inválida!\n";
                        UtilidadesConsole::pausar();
                        continue;
                    }

                    UtilidadesConsole::limparBuffer();
                    UtilidadesConsole::limparTela();

                    switch (opcaoSala) {
                        case 1: {
                            auto salas = repoSalas.listarSalas();
                            if (salas.empty()) {
                                std::cout << "Nenhuma sala cadastrada.\n";
                            } else {
                                std::cout << "===== LISTA DE SALAS =====\n";
                                for (const auto& s : salas) {
                                    std::cout << "ID: " << s.getId() << "\n"
                                              << "Nome: " << s.getNome() << "\n"
                                              << "Capacidade: " << s.getCapacidade() << "\n"
                                              << "Tipo: " << (s.getTipoSala() == Sala::_2D ? "2D" :
                                                              s.getTipoSala() == Sala::_3D ? "3D" : "IMAX")
                                              << "\n---------------------------\n";
                                }
                            }
                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 2: {
                            std::string nome;
                            int capacidade;
                            int tipoSala;

                            std::cout << "===== CADASTRO DE SALA =====\n";
                            std::cout << "Nome da sala: ";
                            std::getline(std::cin, nome);

                            std::cout << "Capacidade: ";
                            std::cin >> capacidade;

                            std::cout << "Tipo da sala (0 = 2D, 1 = 3D, 2 = IMAX): ";
                            std::cin >> tipoSala;
                            UtilidadesConsole::limparBuffer();

                            if (capacidade <= 0 || tipoSala < 0 || tipoSala > 2) {
                                std::cout << "Erro: dados inválidos!\n";
                            } else {
                                repoSalas.adicionarSala(nome, capacidade, static_cast<Sala::TipoSala>(tipoSala));
                                std::cout << "Sala cadastrada com sucesso!\n";
                            }

                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 3: {
                            int id;
                            std::cout << "Informe o ID da sala a ser atualizada: ";
                            std::cin >> id;
                            UtilidadesConsole::limparBuffer();

                            Sala* sala = repoSalas.buscarPorId(id);
                            if (!sala) {
                                std::cout << "Sala com ID " << id << " não encontrada.\n";
                            } else {
                                std::string novoNome;
                                int novaCapacidade, novoTipo;

                                std::cout << "Novo nome (atual: " << sala->getNome() << "): ";
                                std::getline(std::cin, novoNome);
                                std::cout << "Nova capacidade (atual: " << sala->getCapacidade() << "): ";
                                std::cin >> novaCapacidade;
                                std::cout << "Novo tipo (atual: "
                                          << (sala->getTipoSala() == Sala::_2D ? "2D" :
                                              sala->getTipoSala() == Sala::_3D ? "3D" : "IMAX")
                                          << ") [0 = 2D, 1 = 3D, 2 = IMAX]: ";
                                std::cin >> novoTipo;
                                UtilidadesConsole::limparBuffer();

                                if (novoNome.empty()) novoNome = sala->getNome();
                                if (novaCapacidade <= 0) novaCapacidade = sala->getCapacidade();
                                if (novoTipo < 0 || novoTipo > 2)
                                    novoTipo = static_cast<int>(sala->getTipoSala());

                                Sala atualizada(id, novoNome, novaCapacidade, sala->getAssentos(),
                                                static_cast<Sala::TipoSala>(novoTipo));
                                repoSalas.atualizarSala(id, atualizada);
                            }

                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 4: {
                            int id;
                            std::cout << "Informe o ID da sala a ser removida: ";
                            std::cin >> id;
                            UtilidadesConsole::limparBuffer();

                            if (repoSalas.removerSala(id)) {
                                std::cout << "Sala removida com sucesso!\n";
                            } else {
                                std::cout << "Sala com ID " << id << " não encontrada.\n";
                            }

                            UtilidadesConsole::pausar();
                            break;
                        }

                        case 0:
                            std::cout << "Voltando ao menu principal...\n";
                            UtilidadesConsole::pausar();
                            break;

                        default:
                            std::cout << "Opção inválida!\n";
                            UtilidadesConsole::pausar();
                    }
                }
                break;
            }

            // Sessão
            case 3:
                adm.cadastrarSessao();
                UtilidadesConsole::pausar();
                break;

            // Sair do menu administrador
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
