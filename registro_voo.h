#ifndef REGISTRO_VOO_H
#define REGISTRO_VOO_H

#include <iostream>
#include <string>
#include "registrarAstronauta.h"
#include "vector.h"
#include "menu.h"
#include <vector>
#include <algorithm>
#include <string>


class voo{
    private:
        int numeroDeVoo;
        vector<astronauta> cadastro;
        string status_voo = "Planejado";
    public:
        void registra_voo(int numeroDeVoo);
        int dadoNumeroDeVoo() const;
        void registra_astronauta(astronauta& novoAstronauta);
        void imprime_nomes_astronautas();
        void busca_cpf(string cpf);
        void em_voo();
        void kabum();
        void muda_status_astronauta_decolando();
        void muda_status_astronauta_morto();
        void muda_status_astronauta_pouso();
        bool passageiro();
        void planejado();
        string dado_status_voo();
        vector<astronauta> get_cadastro();
        


        
};


#endif