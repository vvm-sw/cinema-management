#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include "Sessao.h"

class Filme {
private:
    std::string nome;
    std::vector<Sessao> sessoes;

public:
    Filme(const std::string& n = "");

    void adicionarSessao(const Sessao& s);
    void mostrarInfo() const;
    const std::string& getNome() const;
    Sessao* getSessaoPtr(int index); //vai retornar um ponteiro para editar/reservar
    int getNumeroSessoes() const;
};

#endif //FILME_H
