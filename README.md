
*Sistema de Controle de Voos*
Um sistema em C++ que gerencia operações relacionadas a voos, aeronaves, pilotos e passageiros. O programa permite o cadastro de entidades, criação de voos, embarque de passageiros e geração de estatísticas detalhadas.

Estrutura do projeto

O sistema é organizado em múltiplas classes, com separação clara de responsabilidades:

Aeronave: Representa uma aeronave (modelo, código, capacidade etc.)
Piloto: Representa um piloto (nome, matrícula, horas de voo etc.)
Passageiro Representa um passageiro (nome, CPF, bilhete etc.)
Voo: Classe principal, que associa aeronave, piloto, copiloto e lista de passageiros.
"SeC"(Salvar e Carregar): Módulo responsável pela leitura/escrita de dados em arquivos CSV.

///
*Funcionalidades*

-Cadastro de aeronaves, pilotos e passageiros
-Criação de voos associando aeronave e tripulação
-Embarque de passageiros com verificação de duplicidade e capacidade
-Listagem de voos e passageiros embarcados
-Geração de relatórios e estatísticas
-Salvamento e carregamento automático de dados via arquivos .csv

///
*Estrutura de arquivos*

Projeto/
├── Aeronave.h / Aeronave.cpp
├── Piloto.h / Piloto.cpp
├── Passageiro.h / Passageiro.cpp
├── Voo.h / Voo.cpp
├── SeC.h / SeC.cpp
├── main.cpp
└── README.md

///
*Arquivos CSV*

Os dados são salvos e lidos automaticamente pelo sistema em arquivos .csv:
aeronaves.csv
pilotos.csv
passageiros.csv
voos.csv

Cada linha representa uma entidade e os campos são separados por ";". Durante a execução, o sistema tentará carregar esses arquivos se existirem, e os sobrescreverá ao salvar.

///
*Execução*

1.Compilar

Use um compilador compatível com C++11 ou superior:

g++ -o voos main.cpp Aeronave.cpp Pessoa.cpp Piloto.cpp Passageiro.cpp Voo.cpp SeC.cpp


2.Executar

./voos

A princípio, você verá o seguinte menu:

======= SISTEMA DE CONTROLE DE VOOS =======

1.Cadastrar aeronave
2.Cadastrar piloto
3.Cadastrar passageiro
4.Criar voo
5.Embarcar passageiro em voo
6.Listar voos
7.Listar passageiros de um voo
8.Gerar relatórios e estatísticas
9.Salvar dados e sair

///

Estatísticas (Opção 8)
Gera relatórios como:

Quantidade de voos por piloto

Voos com mais passageiros

Médias de duração e escalas

///

Requisitos

Terminal para entrada/saída

(Opcional) IDE como Visual Studio ou VSCode

///

Autoria
Cauã Lemos Câmara - 24.1.4035
Kevin Caley Lauar Ferreira Quimatzoyaro - 24.1.4023
Roberto Antonino Menegassi Filho - 24.1.4002


