#include "registrarAstronauta.h"
#include "menu.h"
#include <iostream>
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
                cout << "Digite o CPF do astronauta: ";
                cin >> cpf;
                cout << "Digite o nome do astronauta: ";
                cin >> nome;
                cout << "Digite a idade do astronauta: ";
                cin >> idade;

                vulgo = vulgo.registrarAstronauta(cpf, nome, idade);
                system("clear");
                add_array(registro_astronauta, vulgo);
                length_astronauta++;
                
                cout << "Pressione enter para continuar: ";
                cin.ignore();
                cin.get();
                break;
            }
            case 2:{
                voo foguetao;
                int anota_placa;
                cout << "Digite o número de registro do foguete: ";
                cin >> anota_placa;
                foguetao.registra_voo(anota_placa);
                add_array_2(registro_voo, foguetao);

                break;
            }
            case 3:{
                int placa;
                string cpf;
                cout << "Digite o número de voo: ";
                cin >> placa ;
                cout << "Digite o cpf de registro: ";
                cin >> cpf;
                voo* foguetao = find_voo(registro_voo, placa);
                astronauta* vulgo = find_CPF(registro_astronauta, cpf);
                vulgo->status_abordo();
                vulgo->showMe();

                foguetao->registra_astronauta(*vulgo);
                foguetao->imprime_nomes_astronautas();
                cout << "Pressione enter para continuar: ";
                cin.ignore();
                cin.get();
                break;
            }
            case 4:{
                int placa;
                string cpf;
                cout << "Digite o número do cpf que será retirado: ";
                cin >> cpf;
                cout << "Digite o número de voo a qual será retirado: ";
                cin >> placa ;
                voo* foguetao = find_voo(registro_voo, placa);
                astronauta* vulgo = find_CPF(registro_astronauta, cpf);
                string buscador = vulgo->dadoCpf();
                foguetao->busca_cpf(buscador);
                vulgo->status_nao_abordo();
                foguetao->imprime_nomes_astronautas();
                cout << "Pressione enter para continuar: ";
                cin.ignore();
                cin.get();

                break;
            }
            case 5:{
                int placa;
                cout << "Digite o número de voo a qual irá decolar: ";
                cin >> placa;
                voo* foguetao = find_voo(registro_voo, placa);
                bool tem_passageiro = foguetao->passageiro();
                if(tem_passageiro){
                    foguetao->em_voo();
                    foguetao->muda_status_astronauta_decolando();
                }
                else{
                    cout << "Não há passageiro e, por tanto, não podemos decolar.";
                    cout << "Pressione enter para continuar: ";
                    cin.ignore();
                    cin.get();
                }
                
                break;
            }
            case 6:{
                int placa;
                cout << "Digite o número de voo a qual será explodido: ";
                cin >> placa;
                voo* foguetao = find_voo(registro_voo, placa);
                foguetao->imprime_nomes_astronautas();
                cout << "Pressione enter para continuar: ";
                cin.ignore();
                cin.get();
                foguetao->kabum();
                break;


                foguetao->kabum();
            }
            case 7:{
                int placa;
                cout << "Digite o número de voo a qual será finalizado: ";
                cin >> placa;
                voo* foguetao = find_voo(registro_voo, placa);
                foguetao->muda_status_astronauta_pouso();


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
                                cout << astronauta.dadoNome() << endl;
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
