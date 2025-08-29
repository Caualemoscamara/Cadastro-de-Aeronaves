#include <iostream>
#include <vector>
#include "Aeronave.h"
#include "Piloto.h"
#include "Passageiro.h"
#include "Voo.h"
#include "SeC.h"
using namespace std;
//Header no menu
void menu();

int main() {
    //Recipientes de adição e carregamento de dados
    vector<Aeronave> aeronaves;
    vector<Piloto> pilotos;
    vector<Passageiro> passageiros;
    vector<Voo*> voos;

    //Carrega os dados, se houverem arquivos com os nomes corretos
    carregarDadosCSV(aeronaves, pilotos, passageiros, voos);

    int opcao;
    //Loop do menu, realização de todas as operações
    do {
        //Mostra o menu e pede pela opção
        menu();
        cin >> opcao;
        //Evita coleção de dados lixo em buffer
        cin.ignore();

        switch (opcao) {
        //Cadastro de aeronave
        case 1: {
            //Coleta os dados da aeronave
            string codigo, modelo;
            int capacidade;
            float velocidadeMedia, horasDeAutonomia;
            cout << "Digite o código da aeronave: ";
            getline(cin, codigo);
            //cin >> codigo;
            cout << "Digite o modelo da aeronave: ";
            getline(cin, modelo);
            //cin >> modelo;
            cout << "Digite a capacidade: ";
            cin >> capacidade;
            cout << "Digite a velocidade média: ";
            cin >> velocidadeMedia;
            cout << "Digite as horas de autonomia: ";
            cin >> horasDeAutonomia;
            //Concatena uma nova aeronave na lista
            aeronaves.emplace_back(codigo, modelo, capacidade, velocidadeMedia, horasDeAutonomia);
            break;
        }
        //Adiciona um novo Piloto no sistema
        case 2: {
            //Coleta dados
            string nome, matricula, breve;
            int horasDeVoo;
            cout << "Digite o nome do piloto: ";
            getline(cin, nome);
            //cin >> nome;
            cout << "Digite a matrícula do piloto: ";
            getline(cin, matricula);
            //cin >> matricula;
            cout << "Digite o brevê do piloto: ";
            getline(cin, breve);
            //cin >> breve;
            cout << "Digite as horas de voo do piloto: ";
            cin >> horasDeVoo;
            //Concatena o piloto na lista
            pilotos.emplace_back(nome, matricula, breve, horasDeVoo);
            break;
        }
        case 3: {
            //Coleta de dados
            string nome, cpf, bilhete;
            cout << "Digite o nome do passageiro: ";
            getline(cin, nome);
            //cin >> nome;
            cout << "Digite o CPF do passageiro: ";
            getline(cin, cpf);
            //cin >> cpf;
            cout << "Digite o número do bilhete: ";
            getline(cin, bilhete);
            //cin >> bilhete;
            //Concatena novo passageiro
            passageiros.emplace_back(nome, cpf, bilhete);
            break;
        }
        //Novo voo
        case 4: {
            if(pilotos.size() < 2 || aeronaves.size() == 0){
                cout << "Pilotos insuficientes ou falta de aeronaves.\n";
                break;
            }
            //Coleta dados
            string codigo, origem, destino;
            float distancia;
            int aeronaveIndex, pilotoIndex, copilotoIndex;
            cout << "Digite o código do voo: ";
            getline(cin, codigo);
            //cin >> codigo;
            cout << "Digite a origem: ";
            getline(cin, origem);
            //cin >> origem;
            cout << "Digite o destino: ";
            getline(cin, destino);
            //cin >> destino;
            cout << "Digite a distância: ";
            cin >> distancia;

            //Lista aeronaves e escolhe pelo índice
            cout << "\n-------------------------------------------\n";
            
            for (size_t i = 0; i < aeronaves.size(); ++i) {
                cout << i+1 << ": ";
                aeronaves[i].exibirDados();
                cout << "-------------------------------------------\n";
            }
            do{
                cout << "Escolha uma aeronave pelo índice: ";
                cin >> aeronaveIndex;
                aeronaveIndex--;
            }while(aeronaveIndex < 0 || aeronaveIndex >= aeronaves.size());
            

            //Lista os pilotos e escolhe pelo índice
            cout << "\n-------------------------------------------\n";
            for (size_t i = 0; i < pilotos.size(); ++i) {
                cout << i+1 << ": ";
                pilotos[i].exibirDados();
                cout << "-------------------------------------------\n";
            }
            do{
                cout << "Escolha o piloto pelo índice: ";
                cin >> pilotoIndex;
                pilotoIndex--;
            }while(pilotoIndex < 0 || pilotoIndex >= pilotos.size());

            //Escolhe o copiloto
            cout << "\n-------------------------------------------\n";
            
            for (size_t i = 0; i < pilotos.size(); ++i) {
                cout << i+1 << ": ";
                pilotos[i].exibirDados();
                cout << "-------------------------------------------\n";
            }
            do{
                cout << "Escolha o copiloto pelo índice: ";
                cin >> copilotoIndex;
                copilotoIndex--;
                if(pilotoIndex == copilotoIndex){
                    cout << "Não é possível escolher um piloto já selecionado.\n";
                    copilotoIndex = -1;
                }
            }while(copilotoIndex < 0 || copilotoIndex >= pilotos.size());

            //Concatena um novo Voo
            voos.push_back(new Voo(codigo, origem, destino, distancia, &aeronaves[aeronaveIndex], &pilotos[pilotoIndex], &pilotos[copilotoIndex]));
            break;
        }
        //Embarca Passageiro
        case 5: {
            if(passageiros.size() == 0){
                cout << "Nenhum passageiro cadastrado\n";
                break;
            }
            //Lista e escolhe voo
            int vooIndex, passageiroIndex;
            cout << "\n-------------------------------------------\n";
            for (int i = 0; i < voos.size(); ++i) {
                cout << i+1 << ": ";
                voos[i]->exibirDados();
                cout << "-------------------------------------------\n";
            }
            do{
                cout << "Escolha o voo pelo índice: ";
                cin >> vooIndex;
                vooIndex--;
            }while(vooIndex < 0 || vooIndex >= voos.size());

            if(voos[vooIndex]->getAeronave()->getCapacidade() == voos[vooIndex]->getPassageiros().size()){
                cout << "Aeronave lotada.\n";
                break;
            }

            //Lista e escolhe passageiro
            
            cout << "\n-------------------------------------------\n";
            for (size_t i = 0; i < passageiros.size(); ++i) {
                cout << i+1 << ": ";
                passageiros[i].exibirDados();
                cout << "-------------------------------------------\n";
            }
            do{
                cout << "Escolha o passageiro pelo índice: ";
                cin >> passageiroIndex;
                passageiroIndex--;
            }while(passageiroIndex < 0 || passageiroIndex >= passageiros.size());

            //Caso passageiro já esteja no voo
            for (Passageiro* passageiro : voos[vooIndex]->getPassageiros()) {
                if(passageiros[passageiroIndex].getCPF() == passageiro->getCPF()){
                    cout << "Passageiro já adicionado!\n";
                    break;
                }
            }
            //Adiciona passageiro no voo especificado
            voos[vooIndex]->adicionarPassageiro(&passageiros[passageiroIndex]);
            break;
        }
        case 6: {
            //For avançado que exibe todos os voos disponíveis
            if(voos.size()==0){
                cout << "Sem voos cadastrados.\n";
                break;
            }
            cout << "\n-------------------------------------------\n";
            for (Voo* voo : voos) {
                voo->exibirDados();
                cout << "-------------------------------------------\n";
            }
            break;
        }
        //Lista passageiros de um voo
        case 7: {
            if(voos.size() == 0){
                cout << "Sem voos cadastrados!\n";
                break;
            }
            int vooIndex;
            //Lista e escolhe o voo
            
            cout << "\n-------------------------------------------\n";
            for (int i = 0; i < voos.size(); ++i){
                cout << i+1 << ": ";
                voos[i]->exibirDados();
                cout << "-------------------------------------------\n";
            }
            do{
                cout << "Escolha o voo para listar os passageiros: ";
                cin >> vooIndex;
                vooIndex--;
            }while(vooIndex < 0 || vooIndex >= voos.size());

            //Exibe os passageiros do voo
            voos[vooIndex]->printPassageiros();
            break;
        }
        case 8: {
            //Ponto Extra
            mostrarEstatisticas(voos);
            break;
        }
        case 9:
            //Salva os dados cadastrados
            cout << "Salvando dados e encerrando...\n";
            salvarDadosCSV(aeronaves, pilotos, passageiros, voos);
            break;
        default:
            //Trata inputs inválidos
            cout << "Opção inválida.\n";
            do{
                cout << "Insira um valor entre 1 e 9.\n";
            }while(opcao < 1 || opcao > 9);
        }
    }while (opcao != 9);

    //Libera memória alocada pelos voos e encerra o programa
    for (Voo* voo : voos) {
        delete voo;
    }

    return 0;
}

//Display do menu
void menu() {
    cout << "======= SISTEMA DE CONTROLE DE VOOS =======\n\n";
    cout << "1. Cadastrar aeronave\n";
    cout << "2. Cadastrar piloto\n";
    cout << "3. Cadastrar passageiro\n";
    cout << "4. Criar voo\n";
    cout << "5. Embarcar passageiro em voo\n";
    cout << "6. Listar voos\n";
    cout << "7. Listar passageiros de um voo\n";
    cout << "8. Gerar relatórios e estatísticas\n";
    cout << "9. Salvar dados e sair\n\n";
    cout << "===========================================\n\n";
    cout << "Escolha uma opção: ";
}

