#include "Pessoa.h"

//Construtor
Pessoa::Pessoa(const string& nome) : nome(nome) {}

//Destrutor sem implementação
Pessoa::~Pessoa() {}

//Getter
string Pessoa:: getNome(){return nome;}