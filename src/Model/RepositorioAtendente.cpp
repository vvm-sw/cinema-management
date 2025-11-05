#include "../../include/RepositorioAtendente.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Construtor
RepositorioAtendente::RepositorioAtendente(const std::string& caminho)
    : caminhoArquivo(caminho), ultimoId(0) {
    carregar();
}

// Carrega todos os atendentes e define o maior ID
void RepositorioAtendente::carregar() {
    atendentes.clear();
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
        std::stringstream ss(linha);
        std::string idStr, nome, cargo, salarioStr, usuario, senha;

        std::getline(ss, idStr, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, cargo, ',');
        std::getline(ss, salarioStr, ',');
        std::getline(ss, usuario, ',');
        std::getline(ss, senha, ',');

        if (idStr.empty()) continue;

        int id = std::stoi(idStr);
        double salario = std::stod(salarioStr);

        atendentes.emplace_back(id, nome, salario, usuario, senha);

        // Atualiza o maior ID encontrado
        if (id > ultimoId) {
            ultimoId = id;
        }
    }

    arquivo.close();
}

// Salva todos os atendentes no CSV
void RepositorioAtendente::salvar() const {
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    for (const auto& a : atendentes) {
        arquivo << a.getId() << ","
                << a.getNome() << ","
                << a.getCargo() << ","
                << a.getSalario() << ","
                << a.getUsuario() << ","
                << a.getSenha() << "\n";
    }

    arquivo.close();
}

// Gera o próximo ID automaticamente
int RepositorioAtendente::gerarNovoId() {
    return ++ultimoId;
}

// Adiciona um novo atendente
Atendente& RepositorioAtendente::adicionarAtendente(const std::string& nome, double salario) {
    int novoId = gerarNovoId();
    Atendente novo(novoId, nome, salario);

    atendentes.push_back(novo);
    salvar();

    std::cout << "✅ Atendente adicionado com ID " << novoId << std::endl;
    return atendentes.back();
}

// Lista todos os atendentes
std::vector<Atendente> RepositorioAtendente::listarAtendentes() const {
    return atendentes;
}

// Busca por ID
Atendente* RepositorioAtendente::buscarPorId(int id) {
    for (auto& a : atendentes) {
        if (a.getId() == id) return &a;
    }
    return nullptr;
}

// Atualiza um atendente existente
bool RepositorioAtendente::atualizarAtendente(int id, const Atendente& novoAtendente) {
    for (auto& a : atendentes) {
        if (a.getId() == id) {
            a = novoAtendente;
            salvar();
            std::cout << "Atendente atualizado com sucesso!" << std::endl;
            return true;
        }
    }

    std::cerr << "Erro: atendente com ID " << id << " não encontrado." << std::endl;
    return false;
}

// Remove um atendente pelo ID
bool RepositorioAtendente::removerAtendente(int id) {
    auto it = std::remove_if(atendentes.begin(), atendentes.end(),
                             [id](const Atendente& a) { return a.getId() == id; });

    if (it != atendentes.end()) {
        atendentes.erase(it, atendentes.end());
        salvar();
        std::cout << "Atendente removido com sucesso!" << std::endl;
        return true;
    }

    std::cerr << "Erro: atendente com ID " << id << " não encontrado." << std::endl;
    return false;
}

// Limpa o arquivo CSV
void RepositorioAtendente::limparArquivo() {
    atendentes.clear();
    ultimoId = 0;
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);
    arquivo.close();
    std::cout << "Arquivo de atendentes limpo!" << std::endl;
}

// Autenticação de login
Atendente* RepositorioAtendente::autenticar(const std::string& usuario, const std::string& senha) {
    for (auto& a : atendentes) {
        if (a.getUsuario() == usuario && a.getSenha() == senha) {
            return new Atendente(a); // retorna cópia dinâmica
        }
    }
    return nullptr; // login inválido
}
