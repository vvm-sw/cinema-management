#ifndef FILME_H
#define FILME_H

#include <string>
#include <iostream>

//(classe que vai representar um filme, com informações basicas e suporte para CSV).
class Filme {
private:
    int id; //identificador do filme (usado ao carregar/atribuir IDs de arquivos CSV).
    std::string titulo; //(título do filme).
    std::string genero; //(genero do filme).
    std::string descricao; //(breve descricao do filme).

public: //(construtor padrão).
    Filme();
    Filme(const std::string& t, const std::string& g, const std::string& d);  //(construtor com título, gênero e descrição).
    Filme(int id_, const std::string& t, const std::string& g, const std::string& d); //construtor com ID (usado ao carregar de CSV).

    //metodos de acesso (getters)
    int getId() const;
    std::string getTitulo() const;
    std::string getGenero() const;
    std::string getDescricao() const;

    //metodos de modificacao (setters)
    void setId(int i);
    void setTitulo(const std::string& t);
    void setGenero(const std::string& g);
    void setDescricao(const std::string& d);

    std::string toCSV() const; //vai converter os dados do filme para uma linha CSV
    static Filme fromCSVLine(const std::string& line); //vai criar um objeto (filme) a partir de uma linha CSV
    void exibir() const; //exibe as informacoes
};

#endif // FILME_H
