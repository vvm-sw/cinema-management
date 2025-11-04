
#include <iostream>
#include "../include/Cinema.h"
#include "../include/Sala.h"
#include "../include/RepositorioFilmes.h"
#include "../include/FilmeCLI.h"
#include "../include/Administrador.h"
#include "../include/Atendente.h"
#include "../include/RepositorioAtendente.h"


using namespace std;
int main () {
    Cinema c = Cinema();
    Sala s = Sala();
    s.setNome("2D");
    //c = new cinema();
    c.setNome("UCI");
    c.setEndereco("Av. República do Líbano - Recife/PE");
    struct tm abertura {.tm_hour = 10};
    c.setAbertura(abertura);
    cout << c.getAbertura().tm_hour << endl;
    cout << s.getNome() << endl;

    //RepositorioFilmes repo("filmes.csv");
    //runFilmeMenu(repo); // <-- use a função diretamente

    // teste da classe Administrador
    Administrador admin(1, "Pedro", 5000.0);

    admin.exibirInfo();
    admin.executarTarefa();

    admin.cadastrarFilme();
    admin.cadastrarSala();
    admin.cadastrarSessao();

    // teste da classe Atendente
    Atendente aten(2, "João", 2500.0);

    aten.exibirInfo();
    aten.executarTarefa();

    aten.venderIngresso();
    aten.cancelarVenda();

    // teste do repositorio da classe Atendente
    RepositorioAtendente repo("../data/atendentes.csv");

    // criando
    repo.limparArquivo();
    repo.adicionarAtendente(Atendente(1, "João Silva", 2500.0));
    repo.adicionarAtendente(Atendente(2, "Maria Souza", 2700.0));

    // listando
    auto lista = repo.carregarAtendentes();
    std::cout << "Lista inicial:\n";
    for (const auto& a : lista)
        std::cout << a.getId() << " - " << a.getNome() << " - R$" << a.getSalario() << "\n";

    // atualizar
    if (repo.atualizarAtendente(2, Atendente(2, "Maria Souza", 3000.0)))
        std::cout << "\nAtendente atualizado com sucesso!\n";

    // deletar
    if (repo.removerAtendente(1))
        std::cout << "\nAtendente removido com sucesso!\n";

    // listar
    std::cout << "\nLista após alterações:\n";
    for (const auto& a : repo.carregarAtendentes())
        std::cout << a.getId() << " - " << a.getNome() << " - R$" << a.getSalario() << "\n";

    return 0;
}