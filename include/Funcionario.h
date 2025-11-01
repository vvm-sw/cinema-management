#ifndef CINEMA_MANAGEMENT_FUNCIONARIO_H
#define CINEMA_MANAGEMENT_FUNCIONARIO_H

#include <string>
#include <iostream>

class Funcionario {
public:
    // Construtor e destrutor
    Funcionario(int id, const std::string& nome, const std::string& cargo, double salario);
    virtual ~Funcionario() = default;

    // Getters e Setters
    int getId() const;
    std::string getNome() const;
    std::string getCargo() const;
    double getSalario() const;

    void setNome(const std::string& novoNome);
    void setCargo(const std::string& novoCargo);
    void setSalario(double novoSalario);

    // Métodos
    virtual void exibirInfo() const;
    virtual void executarTarefa() const = 0;
    // o const = 0 meio que diz que essa classe não implementa esse método mas as classes que herdam são obrigadas a implementar sua própria versão

protected:
    int id;
    std::string nome;
    std::string cargo;
    double salario;
};


#endif //CINEMA_MANAGEMENT_FUNCIONARIO_H