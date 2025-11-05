#ifndef CINEMA_MANAGEMENT_REPOSITORIOFILMES_H
#define CINEMA_MANAGEMENT_REPOSITORIOFILMES_H

#include "Filme.h"
#include <vector>
#include <string>

class RepositorioFilmes {
private:
    std::string caminhoArquivo;
    std::vector<Filme> filmes;
    int ultimoId; // controla o último ID usado

    void carregar();   // lê o CSV
    void salvar() const; // grava o CSV
    int gerarNovoId(); // retorna o próximo ID disponível

public:
    explicit RepositorioFilmes(const std::string& caminho);

    // CRUD
    Filme& adicionarFilme(const std::string& titulo, const std::string& genero, const std::string& descricao);
    std::vector<Filme> listarFilmes() const;
    Filme* buscarPorId(int id);
    bool atualizarFilme(int id, const Filme& novoFilme);
    bool removerFilme(int id);

    void limparArquivo();
};

#endif // CINEMA_MANAGEMENT_REPOSITORIOFILMES_H
