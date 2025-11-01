#include "../include/Cinema.h"
using namespace std;
   Cinema::Cinema(const string& nome, const string& endereco, const tm& abertura, const tm& fechamento) : nome(nome), endereco(endereco), abertura(abertura), fechamento(fechamento) {}
  //  {
  //     this->nome = nome;
  //     this->endereco = nome;
  //     this->abertura = abertura;
  //     this->fechamento = fechamento;
  //  }
    Cinema::Cinema() {
      this->nome = "";
      this->endereco = "";
    }
    Cinema::~Cinema(){}
    const string Cinema::getNome() {
      return nome;
    }
    const string Cinema::getEndereco() {
      return endereco;
    }
    const tm Cinema::getAbertura() {
      return abertura;
   }
    const tm Cinema::getFechamento() {
      return fechamento;
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
    const string Cinema::Cinema::toString() {
       return "Nome " + nome + "\nEndereço: " + endereco + "\nAbertura: " + asctime(&abertura) + "\nFechamento: " + asctime(&abertura);
     }