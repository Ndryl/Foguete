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
    cout << status << endl;
}
string astronauta::dadoCpf () const{
    return cpf;
}
string astronauta::dadoNome()const{
    return nome;
}
int astronauta::dadoIdade() const{
    return idade;
}
void astronauta::status_abordo(){
    status = "Em planejamento";
}
void astronauta::status_decolando(){
    status = "Decolando";
}

void astronauta::status_nao_abordo(){
    status = "Disponível";
}
void astronauta::status_morto(){
    status = "Morto";
}
string astronauta::dadoStatus(){
    return status;
}
