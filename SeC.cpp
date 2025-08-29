#include "SeC.h"

using namespace std;

void salvarDadosCSV(const vector<Aeronave>& aeronaves,
                    const vector<Piloto>& pilotos,
                    const vector<Passageiro>& passageiros,
                    const vector<Voo*>& voos) {
    // --------- AERONAVES ----------
    ofstream arqAeronaves("aeronaves.csv");
    arqAeronaves << "Codigo,Modelo,Capacidade,VelocidadeMedia,Autonomia\n";
    for (const auto& a : aeronaves) {
        arqAeronaves << a.getCodigo() << ","
                     << a.getModelo() << ","
                     << a.getCapacidade() << ","
                     << a.getVelocidadeMedia() << ","
                     << a.getAutonomia() << "\n";
    }
    arqAeronaves.close();

    // --------- PESSOAS ----------
    ofstream arqPessoas("pessoas.csv");
    arqPessoas << "CPF,Nome,DadoExtra1,DadoExtra2,Tipo\n";
    for (auto p : passageiros) {
        arqPessoas << p.getCPF() << ","
                   << p.getNome() << ","
                   << p.getBilhete() << ","
                   << "-" << ","
                   << "Passageiro" << "\n";
    }
    for (auto p : pilotos) {
        arqPessoas << p.getMatricula() << ","
                   << p.getNome() << ","
                   << p.getBreve() << ","
                   << p.getHorasDeVoo() << ","
                   << "Piloto" << "\n";
    }
    arqPessoas.close();

    // --------- VOOS ----------
    ofstream arqVoos("voos.csv");
    arqVoos << "Codigo,Origem,Destino,DataHoraSaida,DataHoraChegada,Distancia,DuracaoEstimada,NumeroEscalas,AeronaveCodigo,PilotoMatricula,CopilotoMatricula,PassageirosCPFs\n";
    for (const auto& v : voos) {
        arqVoos << v->getCodigo() << ","
                << v->getOrigem() << ","
                << v->getDestino() << ","
                << v->getSaida() << ","
                << v->getChegada() << ","
                << v->getDistancia() << ","
                << v->getDuracao() << ","
                << v->getEscalas() << ","
                << (v->getAeronave() ? v->getAeronave()->getCodigo() : "") << ","
                << (v->getPiloto() ? v->getPiloto()->getMatricula() : "") << ","
                << (v->getCopiloto() ? v->getCopiloto()->getMatricula() : "") << ",";

        const auto& passageirosVoo = v->getPassageiros();
        for (size_t i = 0; i < passageirosVoo.size(); ++i) {
            arqVoos << passageirosVoo[i]->getCPF();
            if (i != passageirosVoo.size() - 1)
                arqVoos << ";";
        }
        arqVoos << "\n";
    }
    arqVoos.close();

    cout << "Dados salvos com sucesso!\n";
}

void carregarDadosCSV(vector<Aeronave>& aeronaves,
                      vector<Piloto>& pilotos,
                      vector<Passageiro>& passageiros,
                      vector<Voo*>& voos) {
    string linha;

    // --- AERONAVES ---
    ifstream arqAeronaves("aeronaves.csv");
    if (!arqAeronaves.is_open()) {
        cerr << "Erro ao abrir 'aeronaves.csv'\n";
        return;
    }
    getline(arqAeronaves, linha);
    while (getline(arqAeronaves, linha)) {
        stringstream ss(linha);
        string codigo, modelo, capacidade, velocidade, autonomia;
        getline(ss, codigo, ',');
        getline(ss, modelo, ',');
        getline(ss, capacidade, ',');
        getline(ss, velocidade, ',');
        getline(ss, autonomia, ',');

        aeronaves.emplace_back(codigo, modelo, stoi(capacidade), stod(velocidade), stod(autonomia));
    }
    arqAeronaves.close();

    // --- PESSOAS ---
    ifstream arqPessoas("pessoas.csv");
    if (!arqPessoas.is_open()) {
        cerr << "Erro ao abrir 'pessoas.csv'\n";
        return;
    }
    getline(arqPessoas, linha);
    while (getline(arqPessoas, linha)) {
        stringstream ss(linha);
        string id, nome, extra1, extra2, tipo;
        getline(ss, id, ',');
        getline(ss, nome, ',');
        getline(ss, extra1, ',');
        getline(ss, extra2, ',');
        getline(ss, tipo, ',');

        if (tipo == "Passageiro") {
            passageiros.emplace_back(nome, id, extra1);
        } else if (tipo == "Piloto") {
            pilotos.emplace_back(nome, id, extra1, stoi(extra2));
        }
    }
    arqPessoas.close();

    // --- VOOS ---
    ifstream arqVoos("voos.csv");
    if (!arqVoos.is_open()) {
        cerr << "Erro ao abrir 'voos.csv'\n";
        return;
    }
    getline(arqVoos, linha);
    while (getline(arqVoos, linha)) {
        stringstream ss(linha);
        string cod, orig, dest, dhSaida, dhChegada, dist, dur, escalas, codAer, matPil, matCop, passageirosStr;

        getline(ss, cod, ',');
        getline(ss, orig, ',');
        getline(ss, dest, ',');
        getline(ss, dhSaida, ',');
        getline(ss, dhChegada, ',');
        getline(ss, dist, ',');
        getline(ss, dur, ',');
        getline(ss, escalas, ',');
        getline(ss, codAer, ',');
        getline(ss, matPil, ',');
        getline(ss, matCop, ',');
        getline(ss, passageirosStr);

        Aeronave* aeronave = nullptr;
        Piloto* piloto = nullptr;
        Piloto* copiloto = nullptr;

        for (auto& a : aeronaves)
            if (a.getCodigo() == codAer)
                aeronave = &a;

        for (auto& p : pilotos) {
            if (p.getMatricula() == matPil)
                piloto = &p;
            else if (p.getMatricula() == matCop)
                copiloto = &p;
        }

        Voo* v = new Voo(cod, orig, dest, stof(dist), aeronave, piloto, copiloto);
        v->setDataHoraSaida(dhSaida);
        v->setDataHoraChegada(dhChegada);
        v->setDuracaoEstimada(stof(dur));
        v->setNumeroEscalas(stoi(escalas));
        
        stringstream ssPassageiros(passageirosStr);
        string cpf;
        
        while (getline(ssPassageiros, cpf, ';')){
            for (auto& p : passageiros)
                if (p.getCPF() == cpf){
                    v->adicionarPassageiro(&p);
                }  
        }

        voos.push_back(v);
    }
    arqVoos.close();

    cout << "Dados carregados com sucesso dos arquivos CSV!\n";
}
