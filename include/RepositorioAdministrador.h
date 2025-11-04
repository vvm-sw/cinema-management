#ifndef CINEMA_MANAGEMENT_REPOSITORIOADMINISTRADOR_H
#define CINEMA_MANAGEMENT_REPOSITORIOADMINISTRADOR_H

#include "Administrador.h"
#include <vector>
#include <string>

class RepositorioAdministrador {
private:
    std::string caminhoArquivo;
    std::vector<Administrador> administradores;
    int ultimoId; // armazena o último ID usado

    void carregar();  // lê o CSV
    void salvar() const; // grava o CSV
    int gerarNovoId(); // retorna o próximo ID

public:
    explicit RepositorioAdministrador(const std::string& caminho);

    // CRUD
    Administrador& adicionarAdministrador(const std::string& nome, double salario);
    std::vector<Administrador> listarAdministradores() const;
    Administrador* buscarPorId(int id);
    bool atualizarAdministrador(int id, const Administrador& novoAdministrador);
    bool removerAdministrador(int id);

    void limparArquivo();

    // Responsável por autenticar o login
    Administrador* autenticar(const std::string& usuario, const std::string& senha);
};

#endif // CINEMA_MANAGEMENT_REPOSITORIOADMINISTRADOR_H
