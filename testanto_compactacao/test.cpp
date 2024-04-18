//arquivo .cpp

#include "test.h"
#include <iostream>

using namespace std;


astronauta astronauta::cadastro(string cpf, string nome, int idade){
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;

    return *this;
}
void astronauta::showMe(){
    cout << this->cpf<<endl;
    cout<<this->nome<<endl;
    cout<<this->idade<<endl;
}
