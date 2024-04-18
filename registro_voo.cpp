#include <iostream>
#include <string>
#include <vector>
#include "registrarAstronauta.h"
#include "vector.h"
#include "menu.h"
#include "registro_voo.h"

void voo::registra_voo(int numeroDeVoo){
    this->numeroDeVoo = numeroDeVoo;
}
int voo::dadoNumeroDeVoo() const{
    return numeroDeVoo;
}
