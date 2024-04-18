#include <iostream>
#include <string>
#include <vector>
#include "registrarAstronauta.h"
#include "vector.h"
#include "registro_voo.h"
#include "busca.h"


void find_CPF(vector<astronauta>& lista, string cpf){
    for(const auto& interador : lista){
        if(interador.dadoCpf() == cpf){
            return &interador;
        }
    }
    cout<<"Este CPF não está cadastrado." << endl;
}
void find_CPF(vector<voo>& lista, int numero){
    for(const auto& interador : lista){
        if(interador.dadoNumeroDeVoo() == numero){
            return &interador;
        }
    }
    cout<<"Este voo não está cadastrado." << endl;
}