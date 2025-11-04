#include "../../include/RepositorioAdministrador.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// Construtor
RepositorioAdministrador::RepositorioAdministrador(const std::string& caminho)
    : caminhoArquivo(caminho) {}

// Função auxiliar para salvar toda a lista
void RepositorioAdministrador::salvarTodos(const std::vector<Administrador>& administradores) const {
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    for (const auto& adm : administradores) {
        arquivo << adm.getId() << ","
                << adm.getNome() << ","
                << adm.getCargo() << ","
                << adm.getSalario() << "\n";
    }

    arquivo.close();
}

// Create
void RepositorioAdministrador::adicionarAdministrador(const Administrador& administrador) {
    std::ofstream arquivo(caminhoArquivo, std::ios::app);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    arquivo << administrador.getId() << ","
            << administrador.getNome() << ","
            << administrador.getCargo() << ","
            << administrador.getSalario() << "\n";

    arquivo.close();
}

// Read
std::vector<Administrador> RepositorioAdministrador::carregarAdministradores() const {
    std::vector<Administrador> administradores;
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << std::endl;
        return administradores;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string idStr, nome, cargo, salarioStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, cargo, ',');
        std::getline(ss, salarioStr, ',');

        if (idStr.empty()) continue;

        int id = std::stoi(idStr);
        double salario = std::stod(salarioStr);

        administradores.emplace_back(id, nome, salario);
    }

    arquivo.close();
    return administradores;
}

// Read (por ID)
Administrador* RepositorioAdministrador::buscarPorId(int id) const {
    std::vector<Administrador> administradores = carregarAdministradores();
    for (auto& adm : administradores) {
        if (adm.getId() == id) {
            return new Administrador(adm); // retorna cópia dinâmica
        }
    }
    return nullptr; // não encontrado
}

// Update
bool RepositorioAdministrador::atualizarAdministrador(int id, const Administrador& novoAdministrador) {
    std::vector<Administrador> administradores = carregarAdministradores();
    bool encontrado = false;

    for (auto& adm : administradores) {
        if (adm.getId() == id) {
            adm = novoAdministrador;
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        salvarTodos(administradores);
    }

    return encontrado;
}

// Delete
bool RepositorioAdministrador::removerAdministrador(int id) {
    std::vector<Administrador> administradores = carregarAdministradores();
    size_t tamanhoOriginal = administradores.size();

    administradores.erase(
        std::remove_if(administradores.begin(), administradores.end(),
                       [id](const Administrador& adm) { return adm.getId() == id; }),
        administradores.end()
    );

    if (administradores.size() < tamanhoOriginal) {
        salvarTodos(administradores);
        return true;
    }

    return false;
}

// Limpar
void RepositorioAdministrador::limparArquivo() const {
    std::ofstream arquivo(caminhoArquivo, std::ios::trunc);
    arquivo.close();
}