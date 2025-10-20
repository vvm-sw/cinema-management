#include "Filme.h"
#include <iostream>

Filme::Filme(const std::string& n) : nome(n) {}

void Filme::adicionarSessao(const Sessao& s) {
    sessoes.push_back(s);
}

void Filme::mostrarInfo() const {
    std::cout << "Filme: " << nome << std::endl;
    for (size_t i = 0; i < sessoes.size(); ++i) {
        std::cout << "  [" << i+1 << "] ";
        sessoes[i].mostrarInfo();
    }
}

const std::string& Filme::getNome() const {
    return nome;
}

Sessao* Filme::getSessaoPtr(int index) {
    if (index < 0 || index >= static_cast<int>(sessoes.size())) return nullptr;
    return &sessoes[index];
}

int Filme::getNumeroSessoes() const {
    return static_cast<int>(sessoes.size());
}
