#ifndef _CINEMA_REPOSITORIO_H
#define _CINEMA_REPOSITORIO_H
#include "Cinema.h"
#include <vector>
class CinemaRepositorio {
    public:
    CinemaRepositorio();
    ~CinemaRepositorio();
    const Cinema criarCinema(Cinema& cinema);
    const Cinema getCinema(int id);
    const Cinema atualizarCinema(int id, Cinema& cinema);
    const bool deletarCinema(int id);
    const std::vector<Cinema&> getCinemas();  // TODO: Adicionar parâmetro para filtros // Predicate
};
#endif