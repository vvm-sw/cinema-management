#include "../include/Ingresso.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

Ingresso::Ingresso(int id, const Sessao& sessao, double valor, const std::string& tipo)
    : id(id), sessao(sessao), valor(valor), tipo(tipo) {}

int Ingresso::getId() const { 
    return id; 
}

const Sessao& Ingresso::getSessao() const { 
    return sessao; 
}

double Ingresso::getValor() const { 
    return valor; 
}

std::string Ingresso::getTipo() const { 
    return tipo; 
}


void Ingresso::setId(int id_) { 
    id = id_; 
}

void Ingresso::setSessao(const Sessao& sessao_) { 
    sessao = sessao_; 
}

void Ingresso::setValor(double valor_) { 
    valor = valor_; 
}

void Ingresso::setTipo(const std::string& tipo_) { 
    tipo = tipo_; 
}

// converte para CSV
std::string Ingresso::toCSV() const {
    std::ostringstream oss;
    oss << id << ";" 
        << sessao.getId() << ";" 
        << std::fixed << std::setprecision(2) << valor << ";" 
        << tipo;
    return oss.str();
}

// lê CSV
Ingresso Ingresso::fromCSVLine(const std::string& line, const std::map<std::string, Sessao>& sessoes) {
    std::istringstream ss(line);
    std::string id, sessaoId, valorStr, tipo;

    std::getline(ss, id, ';');
    std::getline(ss, sessaoId, ';');
    std::getline(ss, valorStr, ';');
    std::getline(ss, tipo, ';');

    double valor = 0.0;
    try {
        valor = std::stod(valorStr);
    } catch (...) {
        std::cerr << "Erro ao converter valor: " << valorStr << std::endl;
    }

    // Verifica se a sessão existe
    auto it = sessoes.find(sessaoId);
    if (it == sessoes.end()) {
        throw std::runtime_error("Sessão não encontrada para ID: " + sessaoId);
    }

    return Ingresso(id, it->second, valor, tipo);
}

//exibi informação
void Ingresso::exibir() const {
    std::cout << "=== Ingresso ===" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Valor: R$ " << std::fixed << std::setprecision(2) << valor << std::endl;

    std::cout << "\n--- Sessão ---" << std::endl;
    sessao.exibir(); // aproveita o método da classe Sessao
}
