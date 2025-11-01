#include "Filme.h"
#include <sstream>
#include <algorithm>

//construtor padrão: que inicializa os atributos com valores vazios
Filme::Filme() : id(-1), titulo(""), genero(""), descricao("") {}

//construtor sem ID (usado para novos filmes)
Filme::Filme(const std::string& t, const std::string& g, const std::string& d)
    : id(-1), titulo(t), genero(g), descricao(d) {}

// Construtor completo (usado ao carregar de arquivo CSV)
Filme::Filme(int id_, const std::string& t, const std::string& g, const std::string& d)
    : id(id_), titulo(t), genero(g), descricao(d) {}

//getters
int Filme::getId() const { return id; }
std::string Filme::getTitulo() const { return titulo; }
std::string Filme::getGenero() const { return genero; }
std::string Filme::getDescricao() const { return descricao; }

//setters
void Filme::setId(int i) { id = i; }
void Filme::setTitulo(const std::string& t) { titulo = t; }
void Filme::setGenero(const std::string& g) { genero = g; }
void Filme::setDescricao(const std::string& d) { descricao = d; }

//função auxiliar (vai trocar virgulas por (ponto e vírgula) para nao quebrar o CSV)
static std::string escapeCSV(const std::string& s) {
    std::string r = s;
    std::replace(r.begin(), r.end(), ',', ';');
    return r;
}

//vai converter o objeto Filme em uma linha CSV: id,titulo,genero,descricao
std::string Filme::toCSV() const {
    std::ostringstream oss;
    oss << id << "," << escapeCSV(titulo) << "," << escapeCSV(genero) << "," << escapeCSV(descricao);
    return oss.str();
}

//cria um objeto Filme a partir de uma linha CSV
Filme Filme::fromCSVLine(const std::string& line) {
    //espera: id,titulo,genero,descricao
    std::istringstream ss(line);
    std::string token;
    int id = -1;
    std::string titulo, genero, descricao;

    //Nessa condicao ele lê o ID e (converte para inteiro, se possível)
    if (std::getline(ss, token, ',')) {
        try { id = std::stoi(token); } catch(...) { id = -1; }
    }

    //de resto, vai lê os demais campos separados por vírgula
    std::getline(ss, titulo, ',');
    std::getline(ss, genero, ',');
    std::getline(ss, descricao, ',');

    return Filme(id, titulo, genero, descricao);
}

//exibicao das informacoes formatadas no console
void Filme::exibir() const {
    std::cout << "ID: " << id << "\n"
              << "Titulo: " << titulo << "\n"
              << "Genero: " << genero << "\n"
              << "Descricao: " << descricao << "\n";
}
