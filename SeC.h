#ifndef SEC_H
#define SEC_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Aeronave.h"
#include "Pessoa.h"
#include "Passageiro.h"
#include "Piloto.h"
#include "Voo.h"

void salvarDadosCSV(const vector<Aeronave>& aeronaves, const vector<Piloto>& pilotos, const vector<Passageiro>& passageiros, const vector<Voo*>& voos);

void carregarDadosCSV(vector<Aeronave>& aeronaves, vector<Piloto>& pilotos, vector<Passageiro>& passageiros, vector<Voo*>& voos);
#endif