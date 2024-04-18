//arquivo.h

#ifndef TEST_H
#define TEST_H

#include <iostream>

using namespace std;

class astronauta{
    private:
        string cpf;
        string nome;
        int idade;
        string status;
    public:
        astronauta cadastro(string cpf, string nome, int idade);
        void showMe();
};

#endif