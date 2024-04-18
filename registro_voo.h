#ifndef REGISTRO_VOO_H
#define REGISTRO_VOO_H

#include <iostream>
#include <string>
#include "registrarAstronauta.h"
#include "vector.h"
#include "menu.h"
#include <vector>


class voo{
    private:
        int numeroDeVoo;
        vector<astronauta> cadastro;
    public:
        void registra_voo(int numeroDeVoo);
        int dadoNumeroDeVoo() const;
        
};


#endif