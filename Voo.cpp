#include "Voo.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <algorithm>

//Construtores e destrutores
Voo::Voo(const string& codigo, const string& origem, const string& destino, float distancia, Aeronave* aeronave, Piloto* piloto, Piloto* copiloto)
    : codigo(codigo), origem(origem), destino(destino), distancia(distancia), aeronave(aeronave), piloto(piloto), copiloto(copiloto) {
    duracaoEstimada = calcularDuracao();
    numeroEscalas = calcularNumEscalas();
}

Voo::~Voo() {}

//Getters e setters
string Voo::getCodigo(){return codigo;}
string Voo::getOrigem(){return origem;}
string Voo::getDestino(){return destino;}
string Voo::getSaida(){return dataHoraSaida;}
string Voo::getChegada(){return dataHoraChegada;}
float Voo::getDuracao(){return duracaoEstimada;}
float Voo::getDistancia(){return distancia;}
int Voo::getEscalas(){return numeroEscalas;}
Aeronave* Voo::getAeronave(){return aeronave;}
Piloto* Voo::getPiloto(){return piloto;}
Piloto* Voo::getCopiloto(){return copiloto;}
vector<Passageiro*> Voo::getPassageiros(){return passageiros;}
//const vector<Passageiro*>& Voo::getPassageiros() const {return passageiros;}

//Setters
void Voo::setDataHoraSaida(string saida){dataHoraSaida = saida;}
void Voo::setDataHoraChegada(string chegada){dataHoraChegada = chegada;}
void Voo::setDuracaoEstimada(float dur){duracaoEstimada = dur;}
void Voo::setNumeroEscalas(int num){numeroEscalas = num;}


//Duração do voo, em horas
float Voo::calcularDuracao() const {
    return distancia / aeronave->serializar().size(); // Exemplo simplificado
}

int Voo::calcularNumEscalas() const {
    return static_cast<int>(distancia / (aeronave->serializar().size() * 500));
}

string Voo::serializar() const {
    return codigo + "," + origem + "," + destino + "," + to_string(distancia) + "," + to_string(duracaoEstimada);
}

//Manipulações da classe
void Voo::adicionarPassageiro(Passageiro* passageiro) {
    passageiros.push_back(passageiro);
}

void Voo::removerPassageiro(Passageiro* passageiro) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (*it == passageiro) {
            passageiros.erase(it);
            break;
        }
    }
}

void Voo:: printPassageiros(){
    for(int i = 0; i < passageiros.size(); i++){
        passageiros[i]->exibirDados();
    }
}

void Voo::exibirDados() const {
    cout << "Voo: " << codigo << "\nOrigem: " << origem << "\nDestino: " << destino << "\nDistância: " << distancia << "\nEscalas: " << numeroEscalas << "\nDuração Estimada: " << duracaoEstimada << " horas" << endl;
    cout << endl;
    aeronave->exibirDados();
    cout << "\nPiloto: ";
    piloto->exibirDados();
    cout << "Copiloto: ";
    copiloto->exibirDados();
    /*
    for (const auto& passageiro : passageiros) {
        passageiro->exibirDados();
    }
    */
}

//Ponto extra
void mostrarEstatisticas(const vector<Voo*>& voos) {
    cout << "\n===== Estatísticas do Sistema =====\n";

    // Número total de voos
    cout << "Total de voos cadastrados: " << voos.size() << "\n";

    // Média de passageiros por voo
    int totalPassageiros = 0;
    for (const auto& voo : voos) {
        totalPassageiros += voo->getPassageiros().size();
    }
    double mediaPassageiros = voos.empty() ? 0.0 : (double)totalPassageiros / voos.size();
    cout << "Média de passageiros por voo: " << fixed << setprecision(2) << mediaPassageiros << "\n";

    // Aeronaves mais utilizadas
    map<string, int> aeronaveUso;
    for (const auto& voo : voos) {
        string codigoAeronave = voo->aeronave->getCodigo();
        aeronaveUso[codigoAeronave]++;
    }
    
    int maxUso = 0;
    for (const auto& par : aeronaveUso) {
        if (par.second > maxUso) maxUso = par.second;
    }
    cout << "Aeronaves mais utilizadas: ";
    for (const auto& par : aeronaveUso) {
        if (par.second == maxUso) cout << par.first << " ";
    }
    cout << "\n";

    // Passageiros que participaram de mais de um voo
    map<string, int> passageirosFrequentes; // CPF -> contagem
    for (const auto& voo : voos) {
        for (const auto& p : voo->passageiros) {
            passageirosFrequentes[p->getCPF()]++;
        }
    }
    cout << "Passageiros que participaram de mais de um voo:\n";
    for (const auto& par : passageirosFrequentes) {
        if (par.second > 1)
            cout << "- CPF: " << par.first << " (Voos: " << par.second << ")\n";
    }

    // Voos com 90%+ da capacidade
    cout << "Voos com pelo menos 90% da capacidade:\n";
    for (const auto& voo : voos) {
        int capacidade = voo->aeronave->getCapacidade();
        int ocupacao = voo->passageiros.size();
        double percentual = (double)ocupacao / capacidade;
        if (percentual >= 0.9) {
            cout << "- Voo " << voo->codigo << " (" << ocupacao << "/" << capacidade << ")\n";
        }
    }

    // Distância total por aeronave
    map<string, float> distanciaPorAeronave;
    for (const auto& voo : voos) {
        string codigo = voo->aeronave->getCodigo();
        float distancia = voo->distancia; // assuming it's a string with number
        distanciaPorAeronave[codigo] += distancia;
    }

    cout << "Distância total percorrida por cada aeronave:\n";
    for (const auto& par : distanciaPorAeronave) {
        cout << "- " << par.first << ": " << par.second << " km\n";
    }

    cout << "\n====================================\n\n";
}

