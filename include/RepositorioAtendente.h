#ifndef CINEMA_MANAGEMENT_REPOSITORIOATENDENTE_H
#define CINEMA_MANAGEMENT_REPOSITORIOATENDENTE_H

#include "Atendente.h"
#include <vector>
#include <string>

class RepositorioAtendente {
private:
    std::string caminhoArquivo;
    std::vector<Atendente> atendentes;
    int ultimoId; // armazena o último ID usado

    void carregar();  // lê o CSV
    void salvar() const; // grava o CSV
    int gerarNovoId(); // retorna o próximo ID

public:
    explicit RepositorioAtendente(const std::string& caminho);

    // CRUD
    Atendente& adicionarAtendente(const std::string& nome, double salario);
    std::vector<Atendente> listarAtendentes() const;
    Atendente* buscarPorId(int id);
    bool atualizarAtendente(int id, const Atendente& novoAtendente);
    bool removerAtendente(int id);

    void limparArquivo();

    // Responsável por autenticar o login
    Atendente* autenticar(const std::string& usuario, const std::string& senha);
};

#endif // CINEMA_MANAGEMENT_REPOSITORIOATENDENTE_H
