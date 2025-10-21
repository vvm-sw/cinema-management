#include "cinema.h"

   cinema::cinema(const string& nome, const string& endereco, const tm& abertura, const tm& fechamento)
   {
      this->nome = nome;
      this->endereco = nome;
      this->abertura = abertura;
      this->fechamento = fechamento;
   }
    cinema::cinema() {
      this->nome = "";
      this->endereco = "";
    }
    cinema::~cinema(){}
    const string& cinema::getNome() {
      return nome;
    }
    const string& cinema::getEndereco() {
      return endereco;
    }
    const tm& cinema::getAbertura() {
      return abertura;
   }
    const tm& cinema::getFechamento() {
      return fechamento;
   }
    void cinema::setNome(const string nome) {
      this->nome = nome;
    }
    void cinema::setEndereco(const string endereço) {
      this->endereco = endereco;
    }
    void cinema::setAbertura(const tm abertura) {
      this->abertura = abertura;
    }
    void cinema::setFechamento(const tm fechamento)
     {
      this->fechamento = fechamento;
     }
    string cinema::toString() {
       return "Nome " + nome + "\n" + "Endereço: " + endereco + "\n" + "Abertura: " + asctime(&abertura);
     }