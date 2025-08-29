#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>
using namespace std;

class Aeronave {
private:
    string codigo;
    string modelo;
    int capacidade;
    double velocidadeMedia;
    double autonomia;

public:
    Aeronave(const string& codigo, const string& modelo, int capacidade, double velocidade, double autonomia);
    ~Aeronave();

    string getCodigo() const;
    string getModelo() const;
    int getCapacidade() const;
    double getVelocidadeMedia() const;
    double getAutonomia() const;

    string serializar()const;
    void exibirDados() const;
};

#endif