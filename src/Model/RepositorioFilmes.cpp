#include "RepositorioFilmes.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

//construtor - inicializa o repositório com o caminho do arquivo csv e carrega os filmes
RepositorioFilmes::RepositorioFilmes(const std::string& arquivo)
    : caminhoArquivo(arquivo) {
    carregar();
}

void RepositorioFilmes::carregar() {
    filmes.clear();
    std::ifstream in(caminhoArquivo);

    //caso o arquivo não exista (ex: primeira execução), vai apenas retornar
    if (!in) {
        return;
    }

    std::string linha;
    while (std::getline(in, linha)) {
        if (linha.empty()) continue;
        Filme f = Filme::fromCSVLine(linha);
        filmes.push_back(f);
    }
}

//vai escrever todos os filmes atuais no arquivo CSV
void RepositorioFilmes::salvar() const {
    std::ofstream out(caminhoArquivo);
    if (!out) {
        std::cerr << "Erro: não foi possível abrir " << caminhoArquivo << " para escrita.\n";
        return;
    }

    //cada filme é convertido em uma linha CSV
    for (const auto& f : filmes) {
        out << f.toCSV() << "\n";
    }
}

//vai retornar o próximo ID disponível (maior ID atual + 1)
int RepositorioFilmes::nextId() {
    int maxId = 0;
    for (const auto& f : filmes)
        if (f.getId() > maxId) maxId = f.getId();
    return maxId + 1;
}

//vai adicionar um novo filme, atribuindo um ID automaticamente
void RepositorioFilmes::adicionar(const Filme& f) {
    Filme novo = f;
    novo.setId(nextId());
    filmes.push_back(novo);
}

//remove um filme pelo ID. E vai retornar true, caso seja removido com sucesso
bool RepositorioFilmes::removerPorId(int id) {
    auto it = std::remove_if(filmes.begin(), filmes.end(), [id](const Filme& f){ return f.getId() == id; });
    if (it != filmes.end()) {
        filmes.erase(it, filmes.end());
        return true;
    }
    return false;
}

//aqui retorna a lista completa de filmes
std::vector<Filme> RepositorioFilmes::listar() const {
    return filmes;
}

//em casos que não haja filmes no repositório, vai retornar true.
bool RepositorioFilmes::vazio() const {
    return filmes.empty();
}
