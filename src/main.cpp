
#include <iostream>
#include "../include/Cinema.h"
#include "../include/Sala.h"
#include "../include/RepositorioFilmes.h"
#include "../include/FilmeCLI.h"

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

    return 0;
}