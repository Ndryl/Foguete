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
    int length;
    
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
                length++;
                
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
                string fulano;

                cout << "Digite, respectivamente, o número de registro de voo e cpf que queira cadastrar: ";
                cin >> placa;
                find_numero_voo(registro_voo, placa);
                cin >> fulano;
                find_cpf(registro_astronauta, fulano);






                break;
            }
        }
    }

}
