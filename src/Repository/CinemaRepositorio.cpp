#include "../../include/CinemaRepositorio.h"
#include <fstream>
using namespace std;

CinemaRepositorio::CinemaRepositorio(const string &filepath) : filepath(filepath) {}
CinemaRepositorio::~CinemaRepositorio() {}

const std::string CinemaRepositorio::getFilepath()
{
    return this->filepath;
}

const Cinema CinemaRepositorio::criarCinema(Cinema &cinema)
{

    string filepath = getFilepath();
    std::ofstream out(filepath, std::ios_base::app);
    if (!out)
    {
        std::cerr << "Erro: não foi possível abrir " << filepath << " para escrita.\n";
        return Cinema();
        // return;
    }
    out << cinema.toCsv() << "\n";
    return cinema;
}
const Cinema CinemaRepositorio::getCinema(int id)
{
    string filepath = getFilepath();
    std::ifstream in(filepath);

    // caso o arquivo não exista (ex: primeira execução), vai apenas retornar
    if (!in)
    {
        cout << "Arquivo " << filepath << "não encontrado." << endl;
        return Cinema();
    }

    std::string linha;
    while (std::getline(in, linha))
    {
        if (linha.empty())
            continue;
        try
        {
            int csvId = stoi(linha.substr(0, linha.find(',')));
            if (id == csvId)
            {
                in.close();
                return Cinema().csvToCinema(linha);
            }
        }
        catch (...)
        {
            cout << "Erro lendo Cinema ID " << id << endl;
        }
        in.close();
        return Cinema(); // Cinema vazio, checar na camada acima Implementar método isEmpty
    }
}
const Cinema CinemaRepositorio::atualizarCinema(Cinema &cinema)
{
    if(deletarCinema(cinema.getId())) {
        return criarCinema(cinema);
    }
    cout << "Cinema " + to_string(cinema.getId()) + " não encontrado." << endl;
}
const bool CinemaRepositorio::deletarCinema(int id)
{
    string filepath = getFilepath();
    std::ofstream out("cinemas_new.csv", std::ios_base::app);
    std::ifstream in(filepath);

    // caso o arquivo não exista (ex: primeira execução), vai apenas retornar
    if (!in)
    {
        cout << "Arquivo " << filepath << "não encontrado." << endl;
        return false;
    }

    std::string linha;
    while (std::getline(in, linha))
    {
        if (linha.empty())
            continue;
        try
        {
            int csvId = stoi(linha.substr(0, linha.find(',')));
            if (id != csvId)
            {
                out << linha;
            }
        }
        catch (...)
        {
            cout << "Erro lendo Cinema ID " << id << endl;
        }
        in.close();
        out.close();
        remove("cinema.csv");
        rename("cinemas_new.csv", "cinema.csv");
        return false;
    }
}
    const std::vector<Cinema> getCinemas() {
        //
    }
