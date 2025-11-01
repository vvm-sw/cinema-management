#ifndef REPOSITORIOFILMES_H
#define REPOSITORIOFILMES_H

#include "Filme.h"
#include <vector>
#include <string>

//classe responsavel por gerenciar o conjunto de filmes armazenados (permitindo carregar, salvar e manipular os filmes no arquivo csv).
class RepositorioFilmes {
private:
    std::vector<Filme> filmes; //vai listar os filmes armazenados na memória
    std::string caminhoArquivo; //
    int nextId(); //vai gerar o próximo ID disponível para novos filmes

public:
    explicit RepositorioFilmes(const std::string& arquivo); //construtor que define o caminho do arquivo de armazenamento
    void carregar();             //vai carregar do CSV
    void salvar() const;         //vai salva para CSV
    void adicionar(const Filme& f);   //vai adiciona (atribui id automaticamente)
    bool removerPorId(int id);   //vai retornar true se removeu

    std::vector<Filme> listar() const; //aqui retornar a lista completa de filmes
    bool vazio() const; //aqui verifica para saber se o repositório está vazio
};

#endif // REPOSITORIOFILMES_H
