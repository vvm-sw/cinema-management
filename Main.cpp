#include <iostream>
#include <vector>
#include <string>
#include "Filme.h"
#include "Sessao.h"

using namespace std;

void mostrarCatalogo(const vector<Filme>& filmes) {
    cout << "\n=== CATALOGO DE FILMES ===\n";
    for (size_t i = 0; i < filmes.size(); ++i) {
        cout << "[" << i+1 << "] " << filmes[i].getNome() << endl;
    }
    cout << "[0] Sair\n";
}

int main() {
    vector<Filme> filmes;

    //nessa parte vai criar os filmes e sessões
    Filme f1("Tropa de elite");
    f1.adicionarSessao(Sessao("13:30", 20));
    f1.adicionarSessao(Sessao("15:30", 20));
    f1.adicionarSessao(Sessao("17:30", 20));
    filmes.push_back(f1);

    Filme f2("Snowden - Heroi ou Traidor");
    f2.adicionarSessao(Sessao("13:45", 20));
    f2.adicionarSessao(Sessao("16:15", 20));
    f2.adicionarSessao(Sessao("18:45", 20));
    filmes.push_back(f2);

    Filme f3("Velozes e Furiosos 15");
    f3.adicionarSessao(Sessao("13:30", 20));
    f3.adicionarSessao(Sessao("15:30", 20));
    f3.adicionarSessao(Sessao("17:30", 20));
    filmes.push_back(f3);

    int escolha = -1;
    do {
        mostrarCatalogo(filmes);
        cout << "Escolha um filme: ";
        cin >> escolha;

        if (escolha >= 1 && escolha <= static_cast<int>(filmes.size())) {
            Filme &selecionado = filmes[escolha-1];
            cout << "\nVoce escolheu: " << selecionado.getNome() << endl;
            selecionado.mostrarInfo();

            int idxSessao;
            cout << "Escolha a sessao (numero): ";
            cin >> idxSessao;
            Sessao* sess = selecionado.getSessaoPtr(idxSessao-1);
            if (!sess) {
                cout << "Sessao invalida.\n";
                continue;
            }

            int qtd;
            cout << "Quantidade de bilhetes: ";
            cin >> qtd;
            if (sess->reservarLugar(qtd)) {
                int fp;
                cout << "Forma de pagamento [1] Inteira (8.00) [2] Meia (4.00): ";
                cin >> fp;
                cout << "\nCompra confirmada! Filme: " << selecionado.getNome()
                     << " | Sessao: " << idxSessao
                     << " | Ingressos: " << qtd
                     << " | Pagamento: " << (fp == 1 ? "Inteira" : "Meia") << endl;
            } else {
                cout << "Nao ha lugares suficientes nessa sessao.\n";
            }
        }

    } while (escolha != 0);

    cout << "Obrigado por usar o sistema!\n";
    return 0;
}
