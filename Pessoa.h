#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

//Definição de Pessoa
class Pessoa {
//Acesso permitido para classes derivadas
protected:
    string nome;

public:
    //Construtores e Destrutores
    Pessoa(const string& nome);
    virtual ~Pessoa();

    //Getter
    string getNome();

    //Métodos Virtuais Puros
    //Converte para representação textual
    virtual string serializar() const = 0;
    virtual void exibirDados() const = 0;
};

#endif