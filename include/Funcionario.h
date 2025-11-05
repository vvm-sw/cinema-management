#ifndef CINEMA_MANAGEMENT_FUNCIONARIO_H
#define CINEMA_MANAGEMENT_FUNCIONARIO_H

#include <string>
#include <iostream>

class Funcionario {
protected:
    int id;
    std::string nome;
    std::string cargo;
    double salario;
    std::string usuario;
    std::string senha;

public:
    // Construtor e destrutor
    Funcionario(int id, const std::string& nome, const std::string& cargo, double salario, const std::string& usuario = "", const std::string& senha = "");
    virtual ~Funcionario() = default;

    // Getters e Setters
    int getId() const;
    std::string getNome() const;
    std::string getCargo() const;
    double getSalario() const;
    std::string getUsuario() const;
    std::string getSenha() const;

    void setNome(const std::string& novoNome);
    void setCargo(const std::string& novoCargo);
    void setSalario(double novoSalario);
    void setUsuario(const std::string& novoUser);
    void setSenha(const std::string& novaSenha);

    // Métodos
    virtual void exibirInfo() const;
    virtual void executarTarefa() const = 0;

};


#endif //CINEMA_MANAGEMENT_FUNCIONARIO_H