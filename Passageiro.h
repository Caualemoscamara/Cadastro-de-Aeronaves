#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Pessoa.h"
//Classe derivada de pessoa
class Passageiro : public Pessoa {
    string bilhete;
    string cpf;
public:
    //Construtor e destrutor
    Passageiro(const string& nome, const string& cpf, const string& bilhete);
    ~Passageiro();

    //Getters
    string getCPF();
    string getBilhete();

    //Substitui os métodos V.puros da classe pessoa
    string serializar() const override;
    void exibirDados() const override;
};

#endif
