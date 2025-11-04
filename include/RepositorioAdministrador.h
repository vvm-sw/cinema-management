#ifndef CINEMA_MANAGEMENT_REPOSITORIOADMINISTRADOR_H
#define CINEMA_MANAGEMENT_REPOSITORIOADMINISTRADOR_H
#include "Administrador.h"
#include <vector>
#include <string>

class RepositorioAdministrador {
private:
    std::string caminhoArquivo;

    // Função auxiliar para sobrescrever todo o arquivo CSV
    void salvarTodos(const std::vector<Administrador>& administradores) const;

public:
    explicit RepositorioAdministrador(const std::string& caminho);

    // CRUD
    void adicionarAdministrador(const Administrador& administrador);
    std::vector<Administrador> carregarAdministradores() const;
    Administrador* buscarPorId(int id) const;
    bool atualizarAdministrador(int id, const Administrador& novoAdministrador);
    bool removerAdministrador(int id);

    // Limpar o CSV
    void limparArquivo() const;
};


#endif //CINEMA_MANAGEMENT_REPOSITORIOADMINISTRADOR_H