#ifndef REGISTRARARSTRONAUTA_H
#define REGISTRARARSTRONAUTA_H

#include <iostream>
#include <string>

using namespace std;

class astronauta{
    private:
        string cpf;
        string nome;
        int idade;
        string status = "Disponível";
    public:
        astronauta registrarAstronauta(string cpf, string nome, int idade);
        void showMe() const;
        string dadoCpf() const;
        string dadoNome()const;
        int dadoIdade() const;
        void status_abordo();
        void status_decolando();
        void status_nao_abordo();
        void status_morto();
        string dadoStatus();
};

#endif