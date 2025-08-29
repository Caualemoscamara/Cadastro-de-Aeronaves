#ifndef PILOTO_H
#define PILOTO_H

#include "Pessoa.h"
using namespace std;
//Define Piloto como derivada de Pessoa(public)
class Piloto : public Pessoa {
    string matricula;
    string breve;
    int horasDeVoo;
public:
    //Construtores e Destrutores
    Piloto(const string& nome, const string& matricula, const string& breve, int horas);
    ~Piloto();

    //Getters
    string getMatricula();
    string getBreve();
    int getHorasDeVoo();

    string serializar() const override;
    void exibirDados() const override;
};

#endif