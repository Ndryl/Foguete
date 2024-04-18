//arquivo main

#include "test.h"
#include<iostream>

using namespace std;

int main(){
    string cpf, nome;
    int idade;
    astronauta fulanoDeTal;
    cout<<"Digite o cpf do cidadão: ";
    cin >> cpf;
    cout<<"Digite o nome do cidadão: ";
    cin>>nome;
    cout<<"Digite a idade do cidadão: ";
    cin>>idade;
    fulanoDeTal = fulanoDeTal.cadastro(cpf, nome, idade);
    fulanoDeTal.showMe();

    return 0;
}