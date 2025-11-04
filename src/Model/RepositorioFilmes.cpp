#include "../../include/RepositorioFilmes.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Construtor
RepositorioFilmes::RepositorioFilmes(const std::string& caminho)
    : caminhoArquivo(caminho), ultimoId(0) {
    carregar();
}

// Carrega todos os filmes e define o maior ID
void RepositorioFilmes::carregar() {
    filmes.clear();
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

        std::stringstream ss(linha);
        std::string idStr, titulo, genero, descricao;

        std::getline(ss, idStr, ',');
        std::getline(ss, titulo, ',');
        std::getline(ss, genero, ',');
        std::getline(ss, descricao, ',');

        if (idStr.empty()) continue;

        int id = std::stoi(idStr);

        filmes.emplace_back(id, titulo, genero, descricao);

        // Atualiza o maior ID encontrado
        if (id > ultimoId) {
            ultimoId = id;
        }
    }

    arquivo.close();
}

// Salva todos os filmes no CSV
void RepositorioFilmes::salvar() const {
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    for (const auto& f : filmes) {
        arquivo << f.getId() << ","
                << f.getTitulo() << ","
                << f.getGenero() << ","
                << f.getDescricao() << "\n";
    }

    arquivo.close();
}

// Gera o próximo ID automaticamente
int RepositorioFilmes::gerarNovoId() {
    return ++ultimoId;
}

// Adiciona um novo filme
Filme& RepositorioFilmes::adicionarFilme(const std::string& titulo, const std::string& genero, const std::string& descricao) {
    int novoId = gerarNovoId();
    Filme novo(novoId, titulo, genero, descricao);

    filmes.push_back(novo);
    salvar();

    std::cout << "Filme adicionado com ID " << novoId << std::endl;
    return filmes.back();
}

// Lista todos os filmes
std::vector<Filme> RepositorioFilmes::listarFilmes() const {
    return filmes;
}

// Busca por ID
Filme* RepositorioFilmes::buscarPorId(int id) {
    for (auto& f : filmes) {
        if (f.getId() == id) return &f;
    }
    return nullptr;
}

// Atualiza um filme existente
bool RepositorioFilmes::atualizarFilme(int id, const Filme& novoFilme) {
    for (auto& f : filmes) {
        if (f.getId() == id) {
            f = novoFilme;
            salvar();
            std::cout << "Filme atualizado com sucesso!" << std::endl;
            return true;
        }
    }

    std::cerr << "Erro: filme com ID " << id << " não encontrado." << std::endl;
    return false;
}

// Remove um filme pelo ID
bool RepositorioFilmes::removerFilme(int id) {
    auto it = std::remove_if(filmes.begin(), filmes.end(),
                             [id](const Filme& f) { return f.getId() == id; });

    if (it != filmes.end()) {
        filmes.erase(it, filmes.end());
        salvar();
        std::cout << "Filme removido com sucesso!" << std::endl;
        return true;
    }

    std::cerr << "Erro: filme com ID " << id << " não encontrado." << std::endl;
    return false;
}

// Limpa o arquivo CSV
void RepositorioFilmes::limparArquivo() {
    filmes.clear();
    ultimoId = 0;
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);
    arquivo.close();
    std::cout << "Arquivo de filmes limpo!" << std::endl;
}
