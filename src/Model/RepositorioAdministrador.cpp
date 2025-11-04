#include "../../include/RepositorioAdministrador.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Construtor
RepositorioAdministrador::RepositorioAdministrador(const std::string& caminho)
    : caminhoArquivo(caminho), ultimoId(0) {
    carregar();
}

// Carrega todos os administradores para descobrir o maior ID
void RepositorioAdministrador::carregar() {
    administradores.clear();
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

        administradores.emplace_back(id, nome, salario, usuario, senha);

        // ✅ Atualiza o maior ID encontrado
        if (id > ultimoId) {
            ultimoId = id;
        }
    }

    arquivo.close();
}

// Salva o vetor no .csv
void RepositorioAdministrador::salvar() const {
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    for (const auto& adm : administradores) {
        arquivo << adm.getId() << ","
                << adm.getNome() << ","
                << adm.getCargo() << ","
                << adm.getSalario() << ","
                << adm.getUsuario() << ","
                << adm.getSenha() << "\n";
    }

    arquivo.close();
}

// 🔹 Gera o próximo ID automaticamente
int RepositorioAdministrador::gerarNovoId() {
    return ++ultimoId;
}

// Adicionar
Administrador& RepositorioAdministrador::adicionarAdministrador(const std::string& nome, double salario) {
    int novoId = gerarNovoId();
    Administrador novo(novoId, nome, salario);

    administradores.push_back(novo);
    salvar();

    std::cout << "✅ Administrador adicionado com ID " << novoId << std::endl;
    return administradores.back();
}

// Listar
std::vector<Administrador> RepositorioAdministrador::listarAdministradores() const {
    return administradores;
}

// Buscar por id
Administrador* RepositorioAdministrador::buscarPorId(int id) {
    for (auto& adm : administradores) {
        if (adm.getId() == id) return &adm;
    }
    return nullptr;
}

// Atualizar
bool RepositorioAdministrador::atualizarAdministrador(int id, const Administrador& novoAdministrador) {
    for (auto& adm : administradores) {
        if (adm.getId() == id) {
            adm = novoAdministrador;
            salvar();
            std::cout << "Administrador atualizado com sucesso!" << std::endl;
            return true;
        }
    }
    std::cerr << "Erro: administrador com ID " << id << " não encontrado." << std::endl;
    return false;
}

// Deletar por id
bool RepositorioAdministrador::removerAdministrador(int id) {
    auto it = std::remove_if(administradores.begin(), administradores.end(),
                             [id](const Administrador& adm) { return adm.getId() == id; });

    if (it != administradores.end()) {
        administradores.erase(it, administradores.end());
        salvar();
        std::cout << "Administrador removido com sucesso!" << std::endl;
        return true;
    }

    std::cerr << "Erro: administrador com ID " << id << " não encontrado." << std::endl;
    return false;
}

// Limpa o arquivo .csv
void RepositorioAdministrador::limparArquivo() {
    administradores.clear();
    ultimoId = 0;
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);
    arquivo.close();
    std::cout << "Arquivo de administradores limpo!" << std::endl;
}

// Responsável por autenticar o login
Administrador* RepositorioAdministrador::autenticar(const std::string& usuario, const std::string& senha) {
    for (auto& adm : administradores) {
        if (adm.getUsuario() == usuario && adm.getSenha() == senha) {
            // Retorna um novo objeto dinâmico para ser usado no login
            return new Administrador(adm);
        }
    }

    return nullptr; // login inválido
}
