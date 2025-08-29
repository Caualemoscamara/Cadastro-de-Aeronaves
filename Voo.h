#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>
#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
using namespace std;
//Define voo, classe maior que faz uso de todas as outras
class Voo {
    Aeronave* aeronave;
    Piloto* piloto;
    Piloto* copiloto;
    vector<Passageiro*> passageiros;

    string codigo;
    string origem;
    string destino;
    string dataHoraSaida;
    string dataHoraChegada;

    float distancia;
    float duracaoEstimada;
    int numeroEscalas;
public:
    //Construtor de voo
    Voo(const string& codigo, const string& origem, const string& destino, float distancia, Aeronave* aeronave, Piloto* piloto, Piloto* copiloto);
    ~Voo();

    //Getters
    string getCodigo();
    string getOrigem();
    string getDestino();
    string getSaida();
    string getChegada();
    float getDuracao();
    float getDistancia();
    int getEscalas();
    Aeronave* getAeronave();
    Piloto* getPiloto();
    Piloto* getCopiloto();
    vector<Passageiro*> getPassageiros();
    //const vector<Passageiro*>& getPassageiros() const;

    //Setters
    void setDataHoraSaida(string);
    void setDataHoraChegada(string);
    void setDuracaoEstimada(float);
    void setNumeroEscalas(int);


    float calcularDuracao() const;
    int calcularNumEscalas() const;
    string serializar() const;

    //Manipulação da classe
    void adicionarPassageiro(Passageiro* passageiro);
    void removerPassageiro(Passageiro* passageiro);
    void exibirDados() const;
    void printPassageiros();
    //Ponto extra
    friend void mostrarEstatisticas(const vector<Voo*>&);
};



#endif
