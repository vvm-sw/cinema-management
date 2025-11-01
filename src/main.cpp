
#include <iostream>
#include "../include/Cinema.h"
#include "../include/Sala.h"
#include "../include/RepositorioFilmes.h"
#include "../include/FilmeCLI.h"
#include "../include/Administrador.h"
#include "../include/Atendente.h"

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

    RepositorioFilmes repo("filmes.csv");
    runFilmeMenu(repo); // <-- use a função diretamente

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
    return 0;
}