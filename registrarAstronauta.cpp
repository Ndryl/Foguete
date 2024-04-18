#include "registrarAstronauta.h"
#include <iostream>

using namespace std;

astronauta astronauta::registrarAstronauta(string cpf, string nome, int idade){
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    return *this;
}
void astronauta::showMe() const {
    cout<< cpf <<endl;
    cout<< nome <<endl;
    cout<< idade <<endl;
}
string astronauta::dadoCpf () const{
    return cpf;
}
string astronauta::dadoNome() const{
    return nome;
}
int astronauta::dadoIdade() const{
    return idade;
}