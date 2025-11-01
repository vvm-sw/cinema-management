#ifndef _SALA_H
#define _SALA_H
#include <string>
#include <ctime>
#include <vector>

class Sala {
public:
    enum TipoSala { _2D, _3D, IMAX };
private:
    int id;
    TipoSala tipoSala;
    std::string nome;
    int capacidade;
    std::vector<std::vector<bool>> assentos; // Vai ser Matriz de classe Assento (id, estáocupado, ispcd)

public:
    Sala(const int id, const std::string& nome, const int capacidade, std::vector<std::vector<bool>> assentos, const TipoSala tipoSala);
    Sala();
    ~Sala();
    const int getId();
    const TipoSala getTipoSala();
    const std::string getNome();
    const int getCapacidade();
    const std::vector<std::vector<bool>> getAssentos();
    void setId(int id);
    void setTipoSala(TipoSala tipo);
    void setNome(const std::string& nome);
    void setCapacidade(int capacidade);
    void setAssentos(std::vector<std::vector<bool>>& assentos);
    //string toString();
};
#endif
