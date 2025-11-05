#ifndef CINEMA_MANAGEMENT_REPOSITORIOSESSOES_H
#define CINEMA_MANAGEMENT_REPOSITORIOSESSOES_H

#include "Sessao.h"
#include "Filme.h"
#include "Sala.h"
#include <vector>
#include <string>
#include <map>

class RepositorioSessoes {
private:
    std::string caminhoArquivo;
    std::vector<Sessao> sessoes;
    int ultimoId;

    void carregar();   // lê o CSV
    void salvar() const; // grava o CSV
    int gerarNovoId(); // retorna o próximo ID disponível

    // Mapas de filmes e salas (para reconstrução das sessões)
    std::map<int, Filme> filmes;
    std::map<int, Sala> salas;

public:
    explicit RepositorioSessoes(const std::string& caminho,
                                const std::map<int, Filme>& filmesDisponiveis,
                                const std::map<int, Sala>& salasDisponiveis);

    // CRUD
    Sessao& adicionarSessao(const Filme& filme, const Sala& sala, const std::string& horario);
    std::vector<Sessao> listarSessoes() const;
    Sessao* buscarPorId(int id);
    bool atualizarSessao(int id, const Sessao& novaSessao);
    bool removerSessao(int id);

    void limparArquivo();
};

#endif // CINEMA_MANAGEMENT_REPOSITORIOSESSOES_H
