#include <iostream>
#include <string>
#include <vector>
#include "registrarAstronauta.h"
#include "vector.h"
#include "menu.h"
#include "registro_voo.h"
#include <algorithm>

void voo::registra_voo(int numeroDeVoo){
    this->numeroDeVoo = numeroDeVoo;
}
int voo::dadoNumeroDeVoo() const{
    return numeroDeVoo;
}
void voo::registra_astronauta(astronauta& novoAstronauta){
    cadastro.push_back(novoAstronauta);

}
void voo::imprime_nomes_astronautas() {
        // Itera sobre o vetor cadastro e imprime os nomes de cada astronauta
        for (const auto& astronauta : cadastro) {
            cout <<"Nome: " << astronauta.dadoNome() << "| CPF: " << astronauta.dadoCpf() << endl;
        }
}
void voo::busca_cpf(string cpf) {
    auto it = find_if(cadastro.begin(), cadastro.end(), [cpf](const astronauta& a) {
        return a.dadoCpf() == cpf; // Supondo que astronauta tem um método getCpf()
    });

    if (it != cadastro.end()) {
        cadastro.erase(it);
        cout << "Elemento com CPF " << cpf << " removido do vetor." << endl;
    } else {
        cout << "Elemento com CPF " << cpf << " não encontrado no vetor." << endl;
    }
}
void voo::planejado(){
    status_voo = "Planejado";
}
void voo::em_voo(){
    status_voo = "Em curso";
}
void voo::muda_status_astronauta_morto() {
    // Itera sobre o vetor cadastro e modifica o status de cada astronauta
    for (auto& fulano : cadastro) { // Remova a palavra-chave const aqui
        fulano.status_morto();
    }
}

void voo::kabum(){
    status_voo = "Explodiu";

    // Alterar o status dos astronautas para "Morto"
    for (auto& astronauta : cadastro) {
        astronauta.status_morto();
    }
}

void voo::muda_status_astronauta_decolando() {
    // Itera sobre o vetor cadastro e modifica o status de cada astronauta
    for (auto& astronauta : cadastro) { // Remova a palavra-chave const aqui
        astronauta.status_decolando();
    }
}

bool voo::passageiro(){
    if(cadastro.size() > 0){
        return true;
    }
    else{
        return false;
    }
}
void voo::muda_status_astronauta_pouso(){
    status_voo = "Finalizado";
    for (auto& astronauta : cadastro) { // Remova a palavra-chave const aqui
        astronauta.status_nao_abordo();
    }

}
string voo::dado_status_voo(){
    return status_voo;
}
vector<astronauta> voo::get_cadastro() {
    return cadastro;
}




