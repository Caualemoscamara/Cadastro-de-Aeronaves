#include "Piloto.h"
#include <iostream>

//Construtores e Destrutores
Piloto::Piloto(const string& nome, const string& matricula, const string& breve, int horas)
    : Pessoa(nome), matricula(matricula), breve(breve), horasDeVoo(horas) {}

Piloto::~Piloto() {}

//Getters
string Piloto:: getBreve(){return breve;}
int Piloto:: getHorasDeVoo(){return horasDeVoo;}
string Piloto:: getMatricula(){return matricula;}

string Piloto::serializar() const {
    return nome + "," + matricula + "," + breve + "," + to_string(horasDeVoo);
}
void Piloto::exibirDados() const {
    cout << nome << ", Matrícula: " << matricula << ", Brevê: " << breve << ", Horas de Voo: " << horasDeVoo << "\n";
}
