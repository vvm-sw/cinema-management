#ifndef _CINEMA_H
#define _CINEMA_H
#include <string>
#include <ctime>
#include "Funcionario.h"
#include "Sala.h"
class Cinema {
private:
    int id;
    std::string nome;
    std::string endereco;
    std::tm abertura;
    std::tm fechamento;
    std::vector<Sala> salas;
    std::vector<Funcionario*> funcionarios;

public:
    // Cinema(const std::string& nome, const std::string& endereco, const std::tm& abertura, const std::tm& fechamento, const std::vector<Sala>& salas, const std::vector<Funcionario>& funcionarios);
    Cinema(const int id, const std::string& nome, const std::string& endereco, const std::tm& abertura, const std::tm& fechamento, const std::vector<Sala>& salas, const std::vector<Funcionario*> funcionarios);
    Cinema(const int id, const std::string& nome, const std::string& endereco, const std::tm& abertura, const std::tm& fechamento);
    Cinema(const std::string& nome, const std::string& endereco, const std::tm& abertura, const std::tm& fechamento);
    Cinema();  // Optional
    ~Cinema();
    const int getId();
    const std::string getNome();
    const std::string getEndereco();
    const std::tm getAbertura();
    const std::string getAberturaStr();
    const std::tm getFechamento();
    const std::string getFechamentoStr();
    const std::vector<Sala> getSalas();
    const std::vector<Funcionario*> getFuncionarios();
    const std::vector<int> getSalaIds();
    const std::vector<int> getFuncionarioIds();
    void setId(const int id);
    void setNome(const std::string& nome);
    void setEndereco(const std::string& endereco);
    void setAbertura(const std::tm& abertura);
    void setFechamento(const std::tm& fechamento);
    void setSalas (const std::vector<Sala>& salas);
    void setFuncionarios (const std::vector<Funcionario*> funcionarios);
    const std::string toString();
    const std::string toCsv();
    const Cinema csvToCinema(const std::string& line);
    const tm stringToTm (const std::string& horario);
    const bool isEmpty();
};
#endif
