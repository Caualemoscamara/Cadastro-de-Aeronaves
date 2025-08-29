#include "Passageiro.h"
#include <iostream>

//Construtor e Destrutor
Passageiro::Passageiro(const string& nome, const string& cpf, const string& bilhete)
    : Pessoa(nome), cpf(cpf), bilhete(bilhete) {}

Passageiro::~Passageiro() {}

//Getters
string Passageiro::getCPF(){return cpf;}
string Passageiro:: getBilhete(){return bilhete;}


string Passageiro::serializar() const {return nome + "," + cpf + "," + bilhete;}
void Passageiro::exibirDados() const {cout << "Passageiro: " << nome << ", CPF: " << cpf << ", Bilhete: " << bilhete << endl;}
