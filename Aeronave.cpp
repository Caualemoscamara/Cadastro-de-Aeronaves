#include "Aeronave.h"
#include <iostream>

Aeronave::Aeronave(const string& codigo, const string& modelo, int capacidade, double velocidade, double autonomia)
    : codigo(codigo), modelo(modelo), capacidade(capacidade), velocidadeMedia(velocidade), autonomia(autonomia) {}

Aeronave::~Aeronave() {}

string Aeronave::getCodigo() const { return codigo; }
string Aeronave::getModelo() const { return modelo; }
int Aeronave::getCapacidade() const { return capacidade; }
double Aeronave::getVelocidadeMedia() const { return velocidadeMedia; }
double Aeronave::getAutonomia() const { return autonomia; }

void Aeronave::exibirDados() const {
    cout << "Aeronave: " << modelo << " Código[" << codigo << "]\n";
    cout << "Capacidade: " << capacidade << ", Velocidade Média: " << velocidadeMedia << ", Autonomia: " << autonomia << "\n";
}

string Aeronave::serializar() const {
    return codigo + "," + modelo + "," + to_string(capacidade) + "," + to_string(velocidadeMedia) + "," + to_string(autonomia);
}
