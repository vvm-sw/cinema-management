#ifndef SESSAO_H
#define SESSAO_H

#include <string>
#include <map>
#include "Filme.h"
#include "Sala.h"

class Sessao {
private:
    int id;
    Filme filme;
    Sala sala;
    std::string horario; // no formato "HH:MM"

public:
    Sessao() = default;
    Sessao(int id, const Filme& filme, const Sala& sala, const std::string& horario);

    // acesso
    int getId() const;
    Filme getFilme() const;
    Sala getSala() const;
    std::string getHorario() const;

    // modificação
    void setId(int id_);
    void setFilme(const Filme& filme);
    void setSala(const Sala& sala);
    void setHorario(const std::string& horario);

    std::string toCSV() const; // converte para formato CSV
    static Sessao fromCSVLine(const std::string& line,
                          const std::map<int, Filme>& filmes,
                          const std::map<int, Sala>& salas);

    void exibir() const; // vai exibir as informações da sessão
};

#endif
