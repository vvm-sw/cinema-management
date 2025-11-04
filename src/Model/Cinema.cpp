#include "../include/Cinema.h"
#include "../include/Sala.h"
#include "../include/Funcionario.h"
#include "../CsvUtils.h"
#include <vector>
#include <sstream>
using namespace std;

   Cinema::Cinema(const int id, const string& nome, const string& endereco, const tm& abertura, const tm& fechamento, const vector<Sala>& salas, const vector<Funcionario*> funcionarios) : id(id), nome(nome), endereco(endereco), abertura(abertura), fechamento(fechamento), salas(salas), funcionarios(funcionarios) {}
   Cinema::Cinema(const int id, const string& nome, const string& endereco, const tm& abertura, const tm& fechamento) : id(id), nome(nome), endereco(endereco), abertura(abertura), fechamento(fechamento)  {}

    Cinema::Cinema() {
      this->nome = "";
      this->endereco = "";
    }
    Cinema::~Cinema(){}
    const int Cinema::getId() {
      return id;
    }
    const string Cinema::getNome() {
      return nome;
    }
    const string Cinema::getEndereco() {
      return endereco;
    }
    const tm Cinema::getAbertura() {
      return abertura;
   }
    const string Cinema::getAberturaStr() {
      return abertura.tm_hour + ":" + abertura.tm_min;
   }
    const tm Cinema::getFechamento() {
      return fechamento;
   }
    const string Cinema::getFechamentoStr() {
      return fechamento.tm_hour + ":" + fechamento.tm_min;
   }
    const vector<Sala> Cinema::getSalas() {
      return salas;
    }
    const vector<int> Cinema::getSalaIds() {
      vector<int> result;
      for (Sala s : getSalas()) {
        result.push_back(s.getId());
      }
      return result;
    }
    const vector<Funcionario*> Cinema::getFuncionarios() {
      return funcionarios;
    }
    const vector<int> Cinema::getFuncionarioIds() {
      vector<int> result;
      for (const auto& f : getFuncionarios()) {
        result.push_back(f->getId());
      }
      return result;
    }
    void Cinema::setNome(const string& nome) {
      this->nome = nome;
    }
    void Cinema::setEndereco(const string& endereco) {
      this->endereco = endereco;
    }
    void Cinema::setAbertura(const tm& abertura) {
      this->abertura = abertura;
    }
    void Cinema::setFechamento(const tm& fechamento)
   {
      this->fechamento = fechamento;
   }
    void Cinema::setSalas(const std::vector<Sala>& salas) {
      this->salas = salas;
    }
    void Cinema::setFuncionarios(const vector<Funcionario*> funcionarios)
     {
      this->funcionarios = funcionarios;
     }
    const string Cinema::Cinema::toString() {
       return "Nome " + nome + "\nEndereço: " + endereco + "\nAbertura: " + asctime(&abertura) + "\nFechamento: " + asctime(&abertura);
     }

    const string Cinema::toCsv() {
        string result =  std::to_string(getId()) + CsvUtils::escapeCSV(getNome()) + "," + CsvUtils::escapeCSV(getEndereco() + "," + CsvUtils::escapeCSV(getAberturaStr())
         + "," + CsvUtils::escapeCSV(getFechamentoStr()));
     return result;
        // string funcionarios = "";
        //   for (const auto& id : getFuncionarioIds()) {
        //     funcionarios.append(to_string(id) + ";");
        //   }
        // funcionarios.append(",");
        // string salas = "";
        //   for (const auto& id : getSalaIds()) {
        //     salas.append(to_string(id) + ";");
        //   }
    }

    const tm Cinema::stringToTm (const string& horario) {
     int colonIndex = horario.find(':');
     string hora = horario.substr(0, colonIndex);
     string minuto = horario.substr(colonIndex + 1, horario.length() - colonIndex);
     struct tm result {.tm_min = stoi(hora), .tm_hour = stoi(hora)};
     return result;
   }
    const Cinema Cinema::csvToCinema(const std::string& line) {
    // espera: id,titulo,genero,descricao
      std::istringstream ss(line);
      std::string token;
      int id = -1;
      std::string nome, endereco, abertura, fechamento;

      // Nessa condicao ele lê o ID e (converte para inteiro, se possível)
      if (std::getline(ss, token, ',')) {
          try { id = std::stoi(token); } catch(...) { id = -1; }
      }

      // lê os demais campos separados por vírgula
      std::getline(ss, nome, ',');
      std::getline(ss, endereco, ',');
      std::getline(ss, abertura, ',');
      std::getline(ss, fechamento, ',');

      struct tm tmAbertura = Cinema::stringToTm(abertura);
      struct tm tmFechamento = Cinema::stringToTm(fechamento);
      
      return Cinema(id, nome, endereco, tmAbertura, tmFechamento);
    }