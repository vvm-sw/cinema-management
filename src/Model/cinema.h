#ifndef _CINEMA_H
#define _CINEMA_H
#include <string>
#include <time.h>
using namespace std;
class cinema {
private:
    int id;
    string nome;
    string endereco;
    tm abertura;
    tm fechamento;

public:
    cinema(const string& nome, const string& endereco, const tm& abertura, const tm& fechamento);
    cinema();
    ~cinema();
    const string& getNome();
    const string& getEndereco();
    const tm& getAbertura();
    const tm& getFechamento();
    void setNome(string nome);
    void setEndereco(string endereco);
    void setAbertura(tm abertura);
    void setFechamento(tm fechamento);
    string toString();
};
#endif
