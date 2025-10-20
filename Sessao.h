#ifndef SESSAO_H
#define SESSAO_H

#include <string>

class Sessao {
private:
    std::string horario;
    int lugaresDisponiveis;

public:
    Sessao(const std::string& h = "", int lugares = 20);

    void mostrarInfo() const;
    bool reservarLugar(int qtd);
};

#endif //SESSAO_H
