#include "Sessao.h"
#include <iostream>

Sessao::Sessao(const std::string& h, int lugares) {
    horario = h;
    lugaresDisponiveis = lugares;
}

void Sessao::mostrarInfo() const {
    std::cout << horario << " | Lugares disponiveis: " << lugaresDisponiveis << std::endl;
}

bool Sessao::reservarLugar(int qtd) {
    if (qtd <= lugaresDisponiveis && qtd > 0) {
        lugaresDisponiveis -= qtd;
        return true;
    }
    return false;
}
