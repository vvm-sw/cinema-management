#ifndef _CINEMA_H
#define _CINEMA_H
#include <string>
#include <ctime>
class Cinema {
private:
    int id;
    std::string nome;
    std::string endereco;
    std::tm abertura;
    std::tm fechamento;
public:
    Cinema(const std::string& nome, const std::string& endereco, const tm& abertura, const tm& fechamento);
    Cinema();  // Optional
    ~Cinema();
    const std::string getNome();
    const std::string getEndereco();
    const std::tm getAbertura();
    const std::tm getFechamento();
    void setNome(const std::string& nome);
    void setEndereco(const std::string& endereco);
    void setAbertura(const std::tm& abertura);
    void setFechamento(const std::tm& fechamento);
    const std::string toString();
};
#endif
