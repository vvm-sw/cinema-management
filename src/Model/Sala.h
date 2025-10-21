#ifndef _SALA_H
#define _SALA_H
#include <string>
#include <time.h>
#include <vector>
using namespace std;


class Sala {
private:
    int id;
    string nome;
    int capacidade;
    vector<vector<bool>> assentos; // Vai ser Matriz de classe Assento (id, estáocupado, ispcd)

public:
    enum class TipoSala { twoD, threeD, IMAX };
    TipoSala tipoSala;
    Sala(const int id, const string& nome, const int capacidade, vector<vector<bool>> assentos, const TipoSala tipoSala);
    Sala();
    ~Sala();
    const int getId();
    const string& getNome();
    const int getCapacidade();
    const vector<vector<bool>> getAssentos();
    void setId(int id);
    void setNome(string nome);
    void setCapacidade(int capacidade);
    void setAssentos(vector<vector<bool>> assentos);
    //string toString();
};
#endif
