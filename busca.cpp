#include <iostream>
#include <string>
#include <vector>
#include "registrarAstronauta.h"
#include "vector.h"
#include "registro_voo.h"
#include "busca.h"



astronauta* find_CPF(vector<astronauta>& lista, const string& cpf) {
    for(auto& interador : lista) {
        if(interador.dadoCpf() == cpf) {
            return &interador;
        }
    }
    cout << "Este CPF não está cadastrado." << endl;
    return nullptr;
}



voo* find_voo(std::vector<voo>& voos, int numeroDeVoo) {
    for (auto& voo : voos) {
        if (voo.dadoNumeroDeVoo() == numeroDeVoo) {
            return &voo;
        }
    }
    return nullptr;
}

