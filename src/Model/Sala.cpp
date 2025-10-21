#include "Sala.h"

//Sala::Sala(const int id, const string& nome, const int capacidade, vector<vector<bool>> assentos, const TipoSala tipoSala) :
//id(id), nome(nome), capacidade(capacidade), assentos(assentos), tipoSala(tipoSala)
Sala::Sala(const int id, const string& nome, const int capacidade, vector<vector<bool>> assentos, const TipoSala tipoSala) {
    this->id = id;
    this->nome = nome;
    this->capacidade = capacidade;
    this->assentos = assentos;
    this->tipoSala = tipoSala;
}

Sala::Sala() {
    nome = "";
    capacidade = 0;
    assentos = vector<vector<bool>>();
    tipoSala = TipoSala::twoD;
}
Sala::~Sala() {}
const int Sala::getId() {
 return id;
}
const string& Sala::getNome() {
return nome;
}
const int Sala::getCapacidade() {
return capacidade;
}
const vector<vector<bool>> Sala::getAssentos() {
return assentos;
}
void Sala::setId(int id) {
this->id = id;
}
void Sala::setNome(const string nome) {
this->nome = nome;
}
void Sala::setCapacidade(int capacidade) {
this->capacidade = capacidade;
}
void Sala::setAssentos(vector<vector<bool>> assentos) {
this->assentos = assentos;
}