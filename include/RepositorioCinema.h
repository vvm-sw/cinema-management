#ifndef _REPOSITORIO_CINEMA__H
#define _REPOSITORIO_CINEMA_H
#include "Cinema.h"
#include <vector>
class RepositorioCinema {
public:
    RepositorioCinema(const std::string& filepath);
    ~RepositorioCinema();
    const std::string getFilepath();
    const int getNextId();
    const Cinema criarCinema(Cinema& cinema);
    const Cinema getCinema(int id);
    const Cinema atualizarCinema(Cinema& cinema);
    const bool deletarCinema(int id);
    const std::vector<Cinema> getCinemas();  // TODO: Adicionar parâmetro para filtros // Predicate
private:
    std::string filepath;
};
#endif