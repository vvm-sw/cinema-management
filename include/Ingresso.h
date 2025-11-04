#ifndef INGRESSO_H
#define INGRESSO_H

#include <string>
#include <map>
#include "Sessao.h"

class Ingresso {
private:
    int id;       
    Sessao sessao;         // Sessão vinculada
    double valor;          // Valor do ingresso
    std::string tipo;      

public:
    Ingresso() = default;
    Ingresso(int id, const Sessao& sessao, double valor, const std::string& tipo);

    // Acesso
    int getId() const;
    const Sessao& getSessao() const;
    double getValor() const;
    std::string getTipo() const;

    // Modificação
    void setId(int id_);
    void setSessao(const Sessao& sessao_);
    void setValor(double valor_);
    void setTipo(const std::string& tipo_);

    // Utilitários
    std::string toCSV() const; 
    static Ingresso fromCSVLine(const std::string& line, const std::map<std::string, Sessao>& sessoes);
    void exibir() const;
};

#endif
