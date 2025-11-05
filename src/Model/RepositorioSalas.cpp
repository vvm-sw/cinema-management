#include "../../include/RepositorioSalas.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Construtor
RepositorioSalas::RepositorioSalas(const std::string& caminho)
    : caminhoArquivo(caminho), ultimoId(0) {
    carregar();
}

// Carrega todas as salas e define o maior ID
void RepositorioSalas::carregar() {
    salas.clear();
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
        std::string idStr, nome, capacidadeStr, tipoStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, capacidadeStr, ',');
        std::getline(ss, tipoStr, ',');

        if (idStr.empty()) continue;

        int id = std::stoi(idStr);
        int capacidade = std::stoi(capacidadeStr);
        Sala::TipoSala tipo = static_cast<Sala::TipoSala>(std::stoi(tipoStr));

        // Criamos com assentos vazios, por enquanto
        std::vector<std::vector<bool>> assentos;
        salas.emplace_back(id, nome, capacidade, assentos, tipo);

        // Atualiza o maior ID encontrado
        if (id > ultimoId) {
            ultimoId = id;
        }
    }

    arquivo.close();
}

// Salva todas as salas no CSV
void RepositorioSalas::salvar() const {
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    for (const auto& s : salas) {
        arquivo << s.getId() << ","
                << s.getNome() << ","
                << s.getCapacidade() << ","
                << static_cast<int>(s.getTipoSala()) << "\n";
    }

    arquivo.close();
}

// Gera o próximo ID automaticamente
int RepositorioSalas::gerarNovoId() {
    return ++ultimoId;
}

// Adiciona uma nova sala
Sala& RepositorioSalas::adicionarSala(const std::string& nome, int capacidade, Sala::TipoSala tipo) {
    int novoId = gerarNovoId();
    std::vector<std::vector<bool>> assentos;
    Sala nova(novoId, nome, capacidade, assentos, tipo);

    salas.push_back(nova);
    salvar();

    std::cout << "Sala adicionada com ID " << novoId << std::endl;
    return salas.back();
}

// Lista todas as salas
std::vector<Sala> RepositorioSalas::listarSalas() const {
    return salas;
}

// Busca uma sala pelo ID
Sala* RepositorioSalas::buscarPorId(int id) {
    for (auto& s : salas) {
        if (s.getId() == id) return &s;
    }
    return nullptr;
}

// Atualiza uma sala existente
bool RepositorioSalas::atualizarSala(int id, const Sala& novaSala) {
    for (auto& s : salas) {
        if (s.getId() == id) {
            s = novaSala;
            salvar();
            std::cout << "Sala atualizada com sucesso!" << std::endl;
            return true;
        }
    }

    std::cerr << "Erro: sala com ID " << id << " não encontrada." << std::endl;
    return false;
}

// Remove uma sala pelo ID
bool RepositorioSalas::removerSala(int id) {
    auto it = std::remove_if(salas.begin(), salas.end(),
                             [id](const Sala& s) { return s.getId() == id; });

    if (it != salas.end()) {
        salas.erase(it, salas.end());
        salvar();
        std::cout << "Sala removida com sucesso!" << std::endl;
        return true;
    }

    std::cerr << "Erro: sala com ID " << id << " não encontrada." << std::endl;
    return false;
}

// Limpa o arquivo CSV
void RepositorioSalas::limparArquivo() {
    salas.clear();
    ultimoId = 0;
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);
    arquivo.close();
    std::cout << "Arquivo de salas limpo!" << std::endl;
}
