#include "registrarAstronauta.h"
#include "menu.h"
#include <iostream>
#include <cstring> 
#include <vector>
#include "vector.h"
#include "busca.h"
using namespace std;



void menu(){
    int loop = 1;
    vector<astronauta> registro_astronauta;
    vector<voo> registro_voo;
    int length_astronauta, length_voo;
    
    while(loop){
        system("clear");
        cout<<"---------------------MENU--------------------"<<endl;
        cout<<"1: Registrar astronauta"<<endl;
        cout<<"2: Registrar voo"<<endl;
        cout<<"3: Adicionar astronauta em voo"<<endl;
        cout<<"4: Remover astronauta de voo"<<endl;
        cout<<"5: Lançar voo"<<endl;
        cout<<"6: Explodir voo"<<endl;
        cout<<"7: Finalizar voo"<<endl;
        cout<<"8: Listar todos os voos"<<endl;
        cout<<"9: Listar astronautas mortos"<<endl;
        cout<<"0: Sair"<<endl;
        int comando;
        cout<<"Digite a ação que você deseja a seguir: ";
        cin >> comando;
        switch(comando){
            case 0:{
                    loop = comando;
                // for (const auto& astronauta : registro_astronauta){
                //     string dado = astronauta.dadoCpf();
                //     cout << dado << endl;
                // }
                // for (const auto& interador : registro_voo){
                //     int numero = interador.dadoNumeroDeVoo();
                //     cout << numero << endl;
                // }
                break;
            }
            case 1:{
                astronauta vulgo;
                string cpf, nome;
                int idade;
                bool cpf_e_repetido = false;
                cout << "Digite o CPF do astronauta: ";
                cin >> cpf;

                for (auto& astronauta : registro_astronauta) {
                    if (astronauta.dadoCpf() == cpf) {
                        cout << "Este CPF já está registrado" << endl;
                        cpf_e_repetido = true;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                }
                if(!cpf_e_repetido){

                    cout << "Digite o nome do astronauta: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Digite a idade do astronauta: ";
                    cin >> idade;
                vulgo = vulgo.registrarAstronauta(cpf, nome, idade);
                system("clear");
                add_array(registro_astronauta, vulgo);
                length_astronauta++;
                
                cout << "Astronauta registrado com sucesso!! pressione enter para continuar: ";
                cin.ignore();
                cin.get();
                break;
                }else{
                    break;
                }
                

            }
            case 2:{
                voo foguetao;
                int anota_placa;
                bool voo_existe = false;
                cout << "Digite o número de registro do foguete: ";
                cin >> anota_placa;
                for (auto& voo : registro_voo) {
                    if (voo.dadoNumeroDeVoo() == anota_placa) {
                        cout << "O voo já esta registrado" << endl;
                        voo_existe = true;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                }
                if(!voo_existe){

                foguetao.registra_voo(anota_placa);
                add_array_2(registro_voo, foguetao);
                cout << "Voo registrado com sucesso!! pressione enter para continuar: ";
                cin.ignore();
                cin.get();

                break;
                }else{
                    break;
                }

            }
            case 3:{
                int placa;
                string cpf;
                if(registro_voo.empty()){
                    cout<<"Não há voo registrado"<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                }else{
                    system("clear");
                    cout<<"---------------------Voos registrados--------------------"<<endl;
                    for (auto& voo : registro_voo) {
                        if(voo.dado_status_voo() == "Planejado"){
                            cout << voo.dadoNumeroDeVoo() << endl;
                        }
                    }
                    bool existencia;
                    cout << "Digite o número do foguete: ";
                    cin >> placa;
                    
                    for (auto& voo : registro_voo) {
                        if(voo.dadoNumeroDeVoo() == placa){
                            existencia = true;
                            break;
                        }
                        existencia = false;
                    }
                    if(existencia){
                            int contador = 0;
                            system("clear");
                            
                            for(auto& astronauta : registro_astronauta){
                                if(astronauta.dadoStatus() == "Disponível"){
                                    contador++;
                                }
                            }
                            if(contador == 0){
                                cout<<"Não há astronauta disponível para registro"<<endl;
                                cin.ignore();
                                cin.get();
                                break;
                            }else{

                            cout<<"---------------------CPF Disponíveis--------------------"<<endl;
                            for(auto& astronauta : registro_astronauta){
                                if(astronauta.dadoStatus() == "Disponível"){
                                    cout << "CPF: "<<astronauta.dadoCpf()  << " | Nome: "<<astronauta.dadoNome() << endl;
                                    
                                }
                            }
                            cout << "Digite o CPF a qual deseja registrar no voo " << placa <<  ": ";
                            cin >> cpf;
                            voo* foguetao = find_voo(registro_voo, placa);
                            astronauta* vulgo = find_CPF(registro_astronauta, cpf);
                            if(vulgo != nullptr){
                                vulgo->status_abordo();
                            }else{
                                break;
                            }
                            //vulgo->showMe();

                            foguetao->registra_astronauta(*vulgo);
                            foguetao->imprime_nomes_astronautas();
                            cout << "CPF registrado com sucesso!! precione enter para continuar: ";
                            cin.ignore();
                            cin.get();
                            break;
                            }
                        }else{
                        cout <<"Não existe voo com este número"<<endl;
                        cin.ignore();
                        cin.get();
                        break;
                        }
                    }
                    
                    
                
                
            }
            case 4:{
                int placa;
                cout<<"---------------------Voos registrados--------------------"<<endl;
                    for (auto& voo : registro_voo) {
                        cout << voo.dadoNumeroDeVoo() << endl;
                    } 
                cout << "Digite o número de voo a qual deseja retirar o astronauta: ";
                cin >> placa ;
                bool existencia;
                for (auto& voo : registro_voo) {
                    if(voo.dadoNumeroDeVoo() == placa){
                        existencia = true;
                        break;
                    }
                    existencia = false;
                }
                if(existencia){
                    voo* foguetao = find_voo(registro_voo, placa);  
                    cout<<"---------------------CPF Disponíveis no voo--------------------"<<endl;
                    foguetao->imprime_nomes_astronautas();
                    
                    string cpf;
                        
                    cout << "Digite o número do cpf que será retirado: ";
                    cin >> cpf;
                    
                    
                    astronauta* vulgo = find_CPF(registro_astronauta, cpf);
                    if(vulgo != nullptr){

                    string buscador = vulgo->dadoCpf();
                    foguetao->busca_cpf(buscador);
                    vulgo->status_nao_abordo();
                    cout << "Pressione enter para continuar: ";
                    cin.ignore();
                    cin.get();

                    break;
                    }else{
                        break;
                    }
                }else{
                    cout <<"Não existe voo com este número"<<endl;
                        cin.ignore();
                        cin.get();
                    break;
                }
                
                
            }
            case 5:{
                int placa;
                if(registro_voo.empty()){
                    cout<<"Não há voo registrado"<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                cout<<"---------------------Voos Planejados--------------------"<<endl;
                    for (auto& voo : registro_voo) {
                        if(voo.dado_status_voo() == "Planejado"){
                            cout << voo.dadoNumeroDeVoo() << endl;
                        }
                    }
                bool existencia;
               
                cout << "Digite o número de voo a qual irá decolar: ";
                cin >> placa;
                 for (auto& voo : registro_voo) {
                        if(voo.dadoNumeroDeVoo() == placa){
                            existencia = true;
                            break;
                        }
                        existencia = false;
                    }
                if(!existencia){
                    cout <<"Não existe voo com este número"<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                voo* foguetao = find_voo(registro_voo, placa);
                bool tem_passageiro = foguetao->passageiro();
                if(tem_passageiro){
                    foguetao->em_voo();
                    foguetao->muda_status_astronauta_decolando();
                }
                else{
                    cout << "Não há passageiro e, por tanto, não podemos decolar."<<endl;
                    cout << "Pressione enter para continuar: ";
                    cin.ignore();
                    cin.get();
                    break;
                }
                cout << "Voo lançado! precione enter para continuar";
                cin.ignore();
                cin.get();
                
                break;
            }
            case 6:{
                int placa;
                int cont = 0;
                cout<<"---------------------Voos Em curso-------------------"<<endl;
                    for (auto& voo : registro_voo) {
                        if(voo.dado_status_voo() == "Em curso"){
                            cout << voo.dadoNumeroDeVoo() << endl;
                            cont++;
                        }
                    }
                if(cont == 0){
                    cout<<"Não há voos em curso"<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                cout << "Digite o número de voo a qual será explodido: ";
                cin >> placa;
                bool existencia;
                for (auto& voo : registro_voo) {
                    if(voo.dadoNumeroDeVoo() == placa){
                        existencia = true;
                        break;
                    }
                    existencia = false;
                }
                if(!existencia){
                    cout <<"Não existe voo com este número"<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                voo* foguetao = find_voo(registro_voo, placa);
                foguetao->imprime_nomes_astronautas();
                cout << "Voo explodiu!! Pressione enter para continuar: ";
                cin.ignore();
                cin.get();
                foguetao->kabum();
                break;


                foguetao->kabum();
            }
            case 7:{
                int placa;
                int cont = 0;
                cout<<"---------------------Voos Em curso-------------------"<<endl;
                    for (auto& voo : registro_voo) {
                        if(voo.dado_status_voo() == "Em curso"){
                            cout << voo.dadoNumeroDeVoo() << endl;
                            cont++;
                        }
                    }
                if(cont == 0){
                    cout<<"Não há voos em curso"<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                cout << "Digite o número de voo a qual será finalizado: ";
                cin >> placa;
                bool existencia;
                for (auto& voo : registro_voo) {
                    if(voo.dadoNumeroDeVoo() == placa){
                        existencia = true;
                        break;
                    }
                    existencia = false;
                }
                if(!existencia){
                    cout <<"Não existe voo com este número"<<endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
                voo* foguetao = find_voo(registro_voo, placa);
                foguetao->muda_status_astronauta_pouso();
                cout<<"Voo Pousou! precione enter pra continuar:"<<endl;
                    cin.ignore();
                    cin.get();



                break;
            }
            case 8: {
                cout << "Voos planejados: " << endl;
                for (auto& voo : registro_voo) {
                    if (voo.dado_status_voo() == "Planejado") {
                        cout << voo.dadoNumeroDeVoo() << endl;
                    }
                }
                cout << "Voos em curso: " << endl;
                for (auto& voo : registro_voo) {
                    if (voo.dado_status_voo() == "Em curso") {
                        cout << voo.dadoNumeroDeVoo() << endl;
                    }
                }
                cout << "Voos finalizados: " << endl;
                for (auto& voo : registro_voo) {
                    if (voo.dado_status_voo() == "Finalizado") {
                        cout << voo.dadoNumeroDeVoo() << endl;
                    }
                }
                cout << "Voos Explodidos: " << endl;
                for (auto& voo : registro_voo) {
                    if (voo.dado_status_voo() == "Explodiu") {
                        cout << voo.dadoNumeroDeVoo() << endl;
                    }
                }
                cout << "Pressione enter para continuar: ";
                cin.ignore();
                cin.get();
                break;
            }
            case 9:{
                bool encontrouAstronautaMorto = false;
                cout << "Astronautas mortos em voos explodidos:" << endl;
                for (auto& voo : registro_voo) {
                    if (voo.dado_status_voo() == "Explodiu") {
                        encontrouAstronautaMorto = true;
                        for (auto& astronauta : voo.get_cadastro()) {
                            if (astronauta.dadoStatus() == "Morto") {
                                cout << "Nome: " << astronauta.dadoNome() << " | CPF: "<<astronauta.dadoCpf()<<" | Idade: "<<astronauta.dadoIdade() << endl;
                        }
                    }
                    }
                }
                cout << "Pressione enter para continuar: ";
                cin.ignore();
                cin.get();
                
                if (!encontrouAstronautaMorto) {
                    cout << "Nenhum astronauta morto em voos explodidos." << endl;
                    cout << "Pressione enter para continuar: ";
                    cin.ignore();
                    cin.get();
                    break;
                }
                
                break;
            }


        }
    }
}
