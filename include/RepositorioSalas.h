#ifndef CINEMA_MANAGEMENT_REPOSITORIOSALAS_H
#define CINEMA_MANAGEMENT_REPOSITORIOSALAS_H

#include "Sala.h"
#include <vector>
#include <string>

class RepositorioSalas {
private:
    std::string caminhoArquivo;
    std::vector<Sala> salas;
    int ultimoId;

    void carregar();   // Lê o CSV e preenche o vetor
    void salvar() const; // Sobrescreve o CSV
    int gerarNovoId(); // Retorna o próximo ID válido

public:
    explicit RepositorioSalas(const std::string& caminho);

    // CRUD
    Sala& adicionarSala(const std::string& nome, int capacidade, Sala::TipoSala tipo);
    std::vector<Sala> listarSalas() const;
    Sala* buscarPorId(int id);
    bool atualizarSala(int id, const Sala& novaSala);
    bool removerSala(int id);

    void limparArquivo();
};

#endif // CINEMA_MANAGEMENT_REPOSITORIOSALAS_H
