#include "../../include/RepositorioSessoes.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Construtor
RepositorioSessoes::RepositorioSessoes(const std::string& caminho,
                                       const std::map<int, Filme>& filmesDisponiveis,
                                       const std::map<int, Sala>& salasDisponiveis)
    : caminhoArquivo(caminho),
      filmes(filmesDisponiveis),
      salas(salasDisponiveis),
      ultimoId(0) {
    carregar();
}

// Carrega todas as sessões e define o maior ID
void RepositorioSessoes::carregar() {
    sessoes.clear();
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Aviso: não foi possível abrir o arquivo "
                  << caminhoArquivo << ". Será criado automaticamente."
                  << std::endl;
        ultimoId = 0;
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;

        try {
            Sessao sessao = Sessao::fromCSVLine(linha, filmes, salas);
            sessoes.push_back(sessao);

            if (sessao.getId() > ultimoId)
                ultimoId = sessao.getId();
        } catch (const std::exception& e) {
            std::cerr << "Erro ao carregar sessão: " << e.what() << std::endl;
        }
    }

    arquivo.close();
}

// Salva todas as sessões no CSV
void RepositorioSessoes::salvar() const {
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    for (const auto& s : sessoes) {
        arquivo << s.toCSV() << "\n";
    }

    arquivo.close();
}

// Gera o próximo ID automaticamente
int RepositorioSessoes::gerarNovoId() {
    return ++ultimoId;
}

// Adiciona uma nova sessão
Sessao& RepositorioSessoes::adicionarSessao(const Filme& filme, const Sala& sala, const std::string& horario) {
    int novoId = gerarNovoId();
    Sessao novaSessao(novoId, filme, sala, horario);

    sessoes.push_back(novaSessao);
    salvar();

    std::cout << "Sessão adicionada com ID " << novoId << std::endl;
    return sessoes.back();
}

// Lista todas as sessões
std::vector<Sessao> RepositorioSessoes::listarSessoes() const {
    return sessoes;
}

// Busca por ID
Sessao* RepositorioSessoes::buscarPorId(int id) {
    for (auto& s : sessoes) {
        if (s.getId() == id) return &s;
    }
    return nullptr;
}

// Atualiza uma sessão existente
bool RepositorioSessoes::atualizarSessao(int id, const Sessao& novaSessao) {
    for (auto& s : sessoes) {
        if (s.getId() == id) {
            s = novaSessao;
            salvar();
            std::cout << "Sessão atualizada com sucesso!" << std::endl;
            return true;
        }
    }

    std::cerr << "Erro: sessão com ID " << id << " não encontrada." << std::endl;
    return false;
}

// Remove uma sessão pelo ID
bool RepositorioSessoes::removerSessao(int id) {
    auto it = std::remove_if(sessoes.begin(), sessoes.end(),
                             [id](const Sessao& s) { return s.getId() == id; });

    if (it != sessoes.end()) {
        sessoes.erase(it, sessoes.end());
        salvar();
        std::cout << "Sessão removida com sucesso!" << std::endl;
        return true;
    }

    std::cerr << "Erro: sessão com ID " << id << " não encontrada." << std::endl;
    return false;
}

// Limpa o arquivo CSV
void RepositorioSessoes::limparArquivo() {
    sessoes.clear();
    ultimoId = 0;
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);
    arquivo.close();
    std::cout << "Arquivo de sessões limpo!" << std::endl;
}
