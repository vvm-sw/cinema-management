
#include <iostream>
#include "../include/Cinema.h"
#include "../include/Sala.h"
#include "../include/Administrador.h"

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

    // teste da classe Administrador
    Administrador admin(1, "Maria", 5000.0);

    admin.exibirInfo();
    admin.executarTarefa();

    admin.cadastrarFilme();
    admin.cadastrarSala();
    admin.cadastrarSessao();

    return 0;
}