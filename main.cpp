#include <iostream>
using namespace std;
#include <string>
#include "Menu.hpp"

int main(int argc, char const *argv[])
{
    cout << "Bem-vindo ao Centro de Controle Espacial!" << endl;
    cout << endl;
    cout << "Menu Principal: " << endl;
    cout << "Escolha uma opcao abaixo para comecar:" << endl;

    string input;
    int opcao;

    do {
        menuPrincipal();
        getline(cin, input);

        //Validade da Entrada
        try {
            opcao = stoi(input);
        } catch(const exception& e) {
            opcao = 0;
            cout << "Entrada invalida. Por favor, digite um numero." << endl;
            continue;
        }
        
        //Menu Principal
        switch (opcao)
        {
        case 1:
            do {
                menuCadastramento();
                
                getline(cin, input);

                //Validade da Entrada
                try {
                    opcao = stoi(input);
                } catch(const exception& e) {
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }
                
                //Menu Cadastramento
                switch (opcao)
                {
                case 1:
                    cout << "Cadastramento opcao 1" << endl;
                    break;
                case 2:
                    cout << "Cadastramento opcao 2" << endl;
                    break;
                case 3:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                    break;
                }
                system("cls");
            } while (opcao != 3);
            
            break;
        case 2:
            do {
                menuAstronauta();
                getline(cin, input);
                
                //Validade da Entrada
                try {
                    opcao = stoi(input);
                } catch(const exception& e) {
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }

                //Menu Astronauta
                switch (opcao)
                {
                case 1:
                    cout << "Menu Astronauta opcao 1" << endl;
                    break;
                case 2:
                    cout << "Menu Astronauta opcao 2" << endl;
                    break;
                case 3:
                    cout << "Menu Astronauta opcao 3" << endl;
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                    break;
                }
                system("cls");
            } while (opcao != 4);
            break;
        case 3:
            do {
                menuVoos();
                getline(cin, input);
                
                //Validade da Entrada
                try {
                    opcao = stoi(input);
                } catch(const exception& e) {
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }

                //Menu Voos
                switch (opcao)
                {
                case 1:
                    cout << "Menu Voos opcao 1" << endl;
                    break;
                case 2:
                    cout << "Menu Voos opcao 2" << endl;
                    break;
                case 3:
                    cout << "Menu Voos opcao 3" << endl;
                    break;
                 case 4:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                    break;
                }
                system("cls");
            } while (opcao != 4);
            
            break;
        case 4:
            do {
                menuControleTrafego();
                
                getline(cin, input);

                //Validade da Entrada
                try {
                    opcao = stoi(input);
                } catch(const exception& e) {
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }


                //Menu Controle de Trafego
                switch (opcao){
                case 1:
                    cout << "Menu Controle de Trafego opcao 1" << endl;
                    break;
                case 2:
                    cout << "Menu Controle de Trafego opcao 2" << endl;
                    break;
                case 3:
                    cout << "Menu Controle de Trafego opcao 3" << endl;
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                    break;
                }
                system("cls");
            } while (opcao != 4);
            break;
        case 5:
            //Finalizar a Sessao
            cout << "Obrigado por usar os servicos do Centro de Controle Espacial!" << endl;
            break;
        default:
            //Opcao Invalida
            cout << "Opcao invalida"<< endl;
            break;
        }
        system("cls");
    } while (opcao != 5);

    return 0;
}
