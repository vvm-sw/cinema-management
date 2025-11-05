#include "../include/Sala.h"
using namespace std;

// Construtor completo
Sala::Sala(const int id, const string& nome, const int capacidade,
           vector<vector<bool>> assentos, const TipoSala tipoSala)
    : id(id), nome(nome), capacidade(capacidade), assentos(assentos), tipoSala(tipoSala) {}

// Construtor padrão
Sala::Sala()
    : id(0), tipoSala(TipoSala::_2D), nome(""), capacidade(0),
      assentos(vector<vector<bool>>()) {}

// Destrutor
Sala::~Sala() {}

// Getters
int Sala::getId() const {
    return id;
}

Sala::TipoSala Sala::getTipoSala() const {
    return tipoSala;
}

string Sala::getNome() const {
    return nome;
}

int Sala::getCapacidade() const {
    return capacidade;
}

vector<vector<bool>> Sala::getAssentos() const {
    return assentos;
}

//Setters
void Sala::setId(int id) {
    this->id = id;
}

void Sala::setTipoSala(TipoSala tipo) {
    this->tipoSala = tipo;
}

void Sala::setNome(const string& nome) {
    this->nome = nome;
}

void Sala::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}

void Sala::setAssentos(vector<vector<bool>>& assentos) {
    this->assentos = assentos;
}
