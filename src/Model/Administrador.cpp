#include "../../include/Administrador.h"
#include "../../include/View/MenuAdministrador.h"
#include "../../include/RepositorioFilmes.h"
#include "../../include/RepositorioSalas.h"
#include "../../include/RepositorioSessoes.h"
#include <limits>

// Construtor
Administrador::Administrador(int id, const std::string& nome, double salario, const std::string& usuario, const std::string& senha)
    : Funcionario(id, nome, "Administrador", salario, usuario, senha) {}

// Implementação dos Métodos
void Administrador::executarTarefa() const {
    std::cout << "Bem-vindo, Administrador " << nome << "!\n";
    std::cout << "Acessando o painel de gerenciamento...\n\n";
    int opcao = -1;

    while (opcao != 0) {
        // Mostra o menu principal do administrador
        menuAdministrador();

        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: {
                int opFilme = -1;
                while (opFilme != 0) {
                    menuGerenciarFilmes();
                    std::cin >> opFilme;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (opFilme) {
                        case 1:
                            const_cast<Administrador*>(this)->listarFilmes();
                            break;
                        case 2:
                            const_cast<Administrador*>(this)->cadastrarFilme();
                            break;
                        case 3:
                            const_cast<Administrador*>(this)->atualizarFilme();
                            break;
                        case 4:
                            const_cast<Administrador*>(this)->removerFilme();
                            break;
                        case 0:
                            std::cout << "Voltando ao menu principal...\n";
                            break;
                        default:
                            std::cout << "Opção inválida.\n";
                            break;
                    }
                }
                break;
            }
            case 2: {
                int opSala = -1;
                while (opSala != 0) {
                    menuGerenciarSalas();
                    std::cin >> opSala;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (opSala) {
                        case 1:
                            const_cast<Administrador*>(this)->listarSalas();
                            break;
                        case 2:
                            const_cast<Administrador*>(this)->cadastrarSala();
                            break;
                        case 3:
                            const_cast<Administrador*>(this)->atualizarSala();
                            break;
                        case 4:
                            const_cast<Administrador*>(this)->removerSala();
                            break;
                        case 0:
                            std::cout << "Voltando ao menu principal...\n";
                            break;
                        default:
                            std::cout << "Opção inválida.\n";
                            break;
                    }
                }
                break;
            }
            case 3: {
                int opSessao = -1;
                while (opSessao != 0) {
                    menuGerenciarSessoes();
                    std::cin >> opSessao;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (opSessao) {
                        case 1:
                            const_cast<Administrador*>(this)->listarSessoes();
                            break;
                        case 2:
                            const_cast<Administrador*>(this)->cadastrarSessao();
                            break;
                        case 3:
                            const_cast<Administrador*>(this)->atualizarSessao();
                            break;
                        case 4:
                            const_cast<Administrador*>(this)->removerSessao();
                            break;
                        case 0:
                            std::cout << "Voltando ao menu principal...\n";
                            break;
                        default:
                            std::cout << "Opção inválida.\n";
                            break;
                    }
                }
                break;
            }
            case 0:
                std::cout << "Saindo do painel do administrador...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
                break;
        }
    }
}

// Parte responsável por gerenciar e crud dos filmes
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

void Administrador::listarFilmes() {
    RepositorioFilmes repo("../data/filmes.csv");
    const auto& filmes = repo.listarFilmes();

    if (filmes.empty()) {
        std::cout << "Nenhum filme cadastrado.\n";
        return;
    }

    std::cout << "\n===== LISTA DE FILMES =====\n";
    for (const auto& filme : filmes) {
        std::cout << "ID: " << filme.getId() << "\n";
        std::cout << "Título: " << filme.getTitulo() << "\n";
        std::cout << "Gênero: " << filme.getGenero() << "\n";
        std::cout << "Descrição: " << filme.getDescricao() << "\n";
        std::cout << "------------------------------\n";
    }
}

void Administrador::atualizarFilme() {
    RepositorioFilmes repo("../data/filmes.csv");
    std::vector<Filme> filmes = repo.listarFilmes();

    if (filmes.empty()) {
        std::cout << "Nenhum filme cadastrado.\n";
        return;
    }

    listarFilmes();

    int id;
    std::cout << "Digite o ID do filme que deseja atualizar: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Filme* filmeExistente = repo.buscarPorId(id);
    if (!filmeExistente) {
        std::cout << "Filme não encontrado.\n";
        return;
    }

    std::string novoTitulo, novoGenero, novaDescricao;

    std::cout << "Novo título (atual: " << filmeExistente->getTitulo() << "): ";
    std::getline(std::cin, novoTitulo);

    std::cout << "Novo gênero (atual: " << filmeExistente->getGenero() << "): ";
    std::getline(std::cin, novoGenero);

    std::cout << "Nova descrição (atual: " << filmeExistente->getDescricao() << "): ";
    std::getline(std::cin, novaDescricao);

    Filme novoFilme(id,
                    novoTitulo.empty() ? filmeExistente->getTitulo() : novoTitulo,
                    novoGenero.empty() ? filmeExistente->getGenero() : novoGenero,
                    novaDescricao.empty() ? filmeExistente->getDescricao() : novaDescricao);

    repo.atualizarFilme(id, novoFilme);
}

void Administrador::removerFilme() {
    RepositorioFilmes repo("../data/filmes.csv");
    std::vector<Filme> filmes = repo.listarFilmes();

    if (filmes.empty()) {
        std::cout << "Nenhum filme cadastrado.\n";
        return;
    }

    listarFilmes();

    int id;
    std::cout << "Digite o ID do filme que deseja remover: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    repo.removerFilme(id);
}


// Parte responsável por gerenciar e crud de salas
void Administrador::cadastrarSala() {
    std::string nome;
    int capacidade;
    int tipoOpcao;

    std::cout << "===== CADASTRO DE SALA =====\n";
    std::cout << "Nome da sala: ";
    std::getline(std::cin, nome);

    std::cout << "Capacidade da sala: ";
    std::cin >> capacidade;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Tipo da sala (1-2D, 2-3D, 3-IMAX): ";
    std::cin >> tipoOpcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Sala::TipoSala tipo;
    switch (tipoOpcao) {
        case 1:
            tipo = Sala::TipoSala::_2D;
            break;
        case 2:
            tipo = Sala::TipoSala::_3D;
            break;
        case 3:
            tipo = Sala::TipoSala::IMAX;
            break;
        default:
            std::cout << "Tipo inválido. Sala não cadastrada.\n";
            return;
    }

    RepositorioSalas repo("../data/salas.csv");
    repo.adicionarSala(nome, capacidade, tipo);

    std::cout << "\nSala cadastrada com sucesso!\n";
}

void Administrador::listarSalas() {
    RepositorioSalas repo("../data/salas.csv");
    std::vector<Sala> salas = repo.listarSalas();

    if (salas.empty()) {
        std::cout << "Nenhuma sala cadastrada.\n";
        return;
    }

    std::cout << "\n===== LISTA DE SALAS =====\n";
    for (const auto& s : salas) {
        std::cout << "ID: " << s.getId() << "\n";
        std::cout << "Nome: " << s.getNome() << "\n";
        std::cout << "Capacidade: " << s.getCapacidade() << "\n";
        std::cout << "Tipo: ";
        switch (s.getTipoSala()) {
            case Sala::TipoSala::_2D:
                std::cout << "2D\n";
                break;
            case Sala::TipoSala::_3D:
                std::cout << "3D\n";
                break;
            case Sala::TipoSala::IMAX:
                std::cout << "IMAX\n";
                break;
        }
        std::cout << "------------------------------\n";
    }
}

void Administrador::atualizarSala() {
    RepositorioSalas repo("../data/salas.csv");
    std::vector<Sala> salas = repo.listarSalas();

    if (salas.empty()) {
        std::cout << "Nenhuma sala cadastrada.\n";
        return;
    }

    listarSalas();

    int id;
    std::cout << "Digite o ID da sala que deseja atualizar: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Sala* salaExistente = repo.buscarPorId(id);
    if (!salaExistente) {
        std::cout << "Sala não encontrada.\n";
        return;
    }

    std::string novoNome;
    int novaCapacidade;
    int novoTipoOpcao;

    std::cout << "Novo nome (atual: " << salaExistente->getNome() << "): ";
    std::getline(std::cin, novoNome);

    std::cout << "Nova capacidade (atual: " << salaExistente->getCapacidade() << "): ";
    std::string capStr;
    std::getline(std::cin, capStr);

    std::cout << "Novo tipo (1-2D, 2-3D, 3-IMAX) (atual: ";
    switch (salaExistente->getTipoSala()) {
        case Sala::TipoSala::_2D:
            std::cout << "2D): ";
            break;
        case Sala::TipoSala::_3D:
            std::cout << "3D): ";
            break;
        case Sala::TipoSala::IMAX:
            std::cout << "IMAX): ";
            break;
    }
    std::string tipoStr;
    std::getline(std::cin, tipoStr);

    // Mantém valores antigos se o campo estiver em branco
    int capacidadeFinal = capStr.empty() ? salaExistente->getCapacidade() : std::stoi(capStr);
    Sala::TipoSala tipoFinal = salaExistente->getTipoSala();

    if (!tipoStr.empty()) {
        int t = std::stoi(tipoStr);
        if (t >= 1 && t <= 3)
            tipoFinal = static_cast<Sala::TipoSala>(t - 1);
    }

    Sala novaSala(
        id,
        novoNome.empty() ? salaExistente->getNome() : novoNome,
        capacidadeFinal,
        salaExistente->getAssentos(),
        tipoFinal
    );

    repo.atualizarSala(id, novaSala);
}

void Administrador::removerSala() {
    RepositorioSalas repo("../data/salas.csv");
    std::vector<Sala> salas = repo.listarSalas();

    if (salas.empty()) {
        std::cout << "Nenhuma sala cadastrada.\n";
        return;
    }

    listarSalas();

    int id;
    std::cout << "Digite o ID da sala que deseja remover: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    repo.removerSala(id);
}

// Parte responsável por gerenciar e crud de sessões
void Administrador::cadastrarSessao() {
    std::cout << "===== CADASTRO DE SESSÃO =====\n";

    // Carrega repositórios de filmes e salas
    RepositorioFilmes repoFilmes("../data/filmes.csv");
    RepositorioSalas repoSalas("../data/salas.csv");

    auto filmes = repoFilmes.listarFilmes();
    auto salas = repoSalas.listarSalas();

    if (filmes.empty() || salas.empty()) {
        std::cout << "Erro: é necessário ter pelo menos um filme e uma sala cadastrados para criar uma sessão.\n";
        return;
    }

    std::cout << "\nFilmes disponíveis:\n";
    for (const auto& f : filmes) {
        std::cout << f.getId() << " - " << f.getTitulo() << "\n";
    }

    int filmeId;
    std::cout << "Escolha o ID do filme: ";
    std::cin >> filmeId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Filme* filmeSelecionado = repoFilmes.buscarPorId(filmeId);
    if (!filmeSelecionado) {
        std::cout << "Filme não encontrado.\n";
        return;
    }

    std::cout << "\nSalas disponíveis:\n";
    for (const auto& s : salas) {
        std::cout << s.getId() << " - " << s.getNome() << " (" << s.getCapacidade() << " lugares)\n";
    }

    int salaId;
    std::cout << "Escolha o ID da sala: ";
    std::cin >> salaId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Sala* salaSelecionada = repoSalas.buscarPorId(salaId);
    if (!salaSelecionada) {
        std::cout << "Sala não encontrada.\n";
        return;
    }

    std::string horario;
    std::cout << "Horário da sessão (HH:MM): ";
    std::getline(std::cin, horario);

    // Monta mapas exigidos pelo RepositorioSessoes
    std::map<int, Filme> mapaFilmes;
    for (auto& f : filmes) mapaFilmes[f.getId()] = f;
    std::map<int, Sala> mapaSalas;
    for (auto& s : salas) mapaSalas[s.getId()] = s;

    RepositorioSessoes repo("../data/sessoes.csv", mapaFilmes, mapaSalas);
    repo.adicionarSessao(*filmeSelecionado, *salaSelecionada, horario);

    std::cout << "\nSessão cadastrada com sucesso!\n";
}

void Administrador::listarSessoes() {
    RepositorioFilmes repoFilmes("../data/filmes.csv");
    RepositorioSalas repoSalas("../data/salas.csv");

    // Cria mapas de referência
    std::map<int, Filme> mapaFilmes;
    for (auto& f : repoFilmes.listarFilmes()) mapaFilmes[f.getId()] = f;
    std::map<int, Sala> mapaSalas;
    for (auto& s : repoSalas.listarSalas()) mapaSalas[s.getId()] = s;

    RepositorioSessoes repo("../data/sessoes.csv", mapaFilmes, mapaSalas);
    auto sessoes = repo.listarSessoes();

    if (sessoes.empty()) {
        std::cout << "Nenhuma sessão cadastrada.\n";
        return;
    }

    std::cout << "\n===== LISTA DE SESSÕES =====\n";
    for (const auto& sessao : sessoes) {
        std::cout << "ID: " << sessao.getId() << "\n";
        std::cout << "Filme: " << sessao.getFilme().getTitulo() << "\n";
        std::cout << "Sala: " << sessao.getSala().getNome() << "\n";
        std::cout << "Horário: " << sessao.getHorario() << "\n";
        std::cout << "------------------------------\n";
    }
}

void Administrador::atualizarSessao() {
    RepositorioFilmes repoFilmes("../data/filmes.csv");
    RepositorioSalas repoSalas("../data/salas.csv");

    std::map<int, Filme> mapaFilmes;
    for (auto& f : repoFilmes.listarFilmes()) mapaFilmes[f.getId()] = f;
    std::map<int, Sala> mapaSalas;
    for (auto& s : repoSalas.listarSalas()) mapaSalas[s.getId()] = s;

    RepositorioSessoes repo("../data/sessoes.csv", mapaFilmes, mapaSalas);
    auto sessoes = repo.listarSessoes();

    if (sessoes.empty()) {
        std::cout << "Nenhuma sessão cadastrada.\n";
        return;
    }

    listarSessoes();

    int id;
    std::cout << "Digite o ID da sessão que deseja atualizar: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Sessao* sessaoExistente = repo.buscarPorId(id);
    if (!sessaoExistente) {
        std::cout << "Sessão não encontrada.\n";
        return;
    }

    std::cout << "Novo horário (atual: " << sessaoExistente->getHorario() << "): ";
    std::string novoHorario;
    std::getline(std::cin, novoHorario);
    if (novoHorario.empty()) novoHorario = sessaoExistente->getHorario();

    repo.atualizarSessao(id, Sessao(id, sessaoExistente->getFilme(), sessaoExistente->getSala(), novoHorario));
}

void Administrador::removerSessao() {
    RepositorioFilmes repoFilmes("../data/filmes.csv");
    RepositorioSalas repoSalas("../data/salas.csv");

    std::map<int, Filme> mapaFilmes;
    for (auto& f : repoFilmes.listarFilmes()) mapaFilmes[f.getId()] = f;
    std::map<int, Sala> mapaSalas;
    for (auto& s : repoSalas.listarSalas()) mapaSalas[s.getId()] = s;

    RepositorioSessoes repo("../data/sessoes.csv", mapaFilmes, mapaSalas);
    auto sessoes = repo.listarSessoes();

    if (sessoes.empty()) {
        std::cout << "Nenhuma sessão cadastrada.\n";
        return;
    }

    listarSessoes();

    int id;
    std::cout << "Digite o ID da sessão que deseja remover: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    repo.removerSessao(id);
}