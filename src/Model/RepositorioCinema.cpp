#include "../../include/RepositorioCinema.h"
#include <fstream>

#include "../CsvUtils.h"
using namespace std;

RepositorioCinema::RepositorioCinema(const string &filepath) : filepath(filepath) {}
RepositorioCinema::~RepositorioCinema() {}

const std::string RepositorioCinema::getFilepath()
{
    return this->filepath;
}

const Cinema RepositorioCinema::criarCinema(Cinema &cinema)
{
    string filepath = getFilepath();
    std::ofstream out(filepath, std::ios_base::app);
    if (!out)
    {
        std::cerr << "Erro: não foi possível abrir " << filepath << " para escrita.\n";
        return Cinema();
        // return;
    }
    if (cinema.getId() == -1)
        cinema.setId(CsvUtils::getNextId("id_counter.txt"));

    out << cinema.toCsv() << "\n";
    return cinema;
}
const Cinema RepositorioCinema::getCinema(int id)
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
        return Cinema();
    }
}
const Cinema RepositorioCinema::atualizarCinema(Cinema &cinema)
{
    if (deletarCinema(cinema.getId()))
    {
        return criarCinema(cinema);
    }
    cout << "Cinema " + to_string(cinema.getId()) + " não encontrado." << endl;
    return Cinema();
}
const bool RepositorioCinema::deletarCinema(int id)
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
    bool found = false;
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
                found = true;
                cout << "Found record " << id << " to delete." << endl;
                continue;
            }
            out << linha;
        }
        catch (...)
        {
            cout << "Erro lendo Cinema ID " << id << endl;
        }
    }
    in.close();
    out.close();
    remove("cinemas.csv");
    rename("cinemas_new.csv", "cinemas.csv");
    return found;
}
const std::vector<Cinema> RepositorioCinema::getCinemas()
{
    ifstream in = ifstream(getFilepath());
    vector<Cinema> result;
    std::string linha;
    while (std::getline(in, linha))
    {
        if (linha.empty()) continue;
        Cinema c = c.csvToCinema(linha);
        result.push_back(c);
    }
    return result;
}
