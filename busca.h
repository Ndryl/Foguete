#ifndef BUSCA_H
#define BUSCA_H

#include <iostream>
#include <string>
#include <vector>
#include "registrarAstronauta.h"
#include "registro_voo.h"



astronauta* find_CPF(vector<astronauta>& lista, const string& cpf);
voo* find_voo(std::vector<voo>& voos, int numeroDeVoo);






#endif