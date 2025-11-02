#include "../../include/Sessao.h"
#include <iostream>
#include <sstream>
#include <map>

Sessao::Sessao(const std::string& id, const Filme& filme, const Sala& sala, const std::string& horario)
    : id(id), filme(filme), sala(sala), horario(horario) {}

std::string Sessao::getId() const {
    return id;
}

Filme Sessao::getFilme() const {
    return filme;
}

Sala Sessao::getSala() const {
    return sala;
} 

std::string Sessao::getHorario() const {
    return horario;
}

void Sessao::setId(const std::string& id_) {
this->id = id_;
}

void Sessao::setFilme(const Filme& filme) {
    this->filme = filme;
}

void Sessao::setSala(const Sala& sala) {
    this->sala = sala;
}

void Sessao::setHorario(const std::string& horario_) {
    this->horario = horario_;
}

// Converte para formato CSV
std::string Sessao::toCSV() const {
    std::ostringstream oss;
    oss << id << ";"
        << filme.getId() << ";" // assumindo que Filme tem getId()
        << sala.getId() << ";"  // assumindo que Sala tem getId()
        << horario;
    return oss.str();
}

// Cria Sessao a partir de linha CSV e mapas de filmes e salas
Sessao Sessao::fromCSVLine(const std::string& line, 
                           const std::map<int, Filme>& filmes, 
                           const std::map<int, Sala>& salas) {
    std::istringstream ss(line);
    std::string token;
    int id = -1, filmeId = -1, salaId = -1;
    std::string horario;

    if (std::getline(ss, token, ';')) id = std::stoi(token);
    if (std::getline(ss, token, ';')) filmeId = std::stoi(token);
    if (std::getline(ss, token, ';')) salaId = std::stoi(token);
    std::getline(ss, horario, ';');

    Filme filme = filmes.at(filmeId); // buscar pelo ID no mapa
    Sala sala = salas.at(salaId);     // buscar pelo ID no mapa

    return Sessao(id, filme, sala, horario);
}

// Exibe informações
void Sessao::exibir() const {
    std::cout << "Sessão ID: " << id << "\n"
              << "Filme: " << filme.getTitulo() << "\n"
              << "Sala: " << sala.getNumero() << "\n"
              << "Horário: " << horario << "\n";
}
