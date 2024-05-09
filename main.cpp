#include <iostream>
#include <string>

#include "Menu.hpp"
#include "ControleTrafego.hpp"
#include "Astronauta.hpp"
#include "Voos.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Bem-vindo ao Centro de Controle Espacial!" << endl;
    cout << endl;
    cout << "Menu Principal: " << endl;
    cout << "Escolha uma opcao abaixo para comecar:" << endl;

    
    string input;
    int opcao;

    //Declarações para ControleTrafego
    ControleTrafego controle;


    do {
        menuPrincipal();
        getline(cin, input);

        //Validade da Entrada
        try {
            opcao = stoi(input);
            system("cls");
        } catch(const exception& e) {
            system("cls");
            cout << "Entrada invalida. Por favor, digite um numero." << endl;
            continue;
        }

        //Menu Principal
       
        switch (opcao){
        
        //Menu Cadastramento
        case 1:
            do {
                menuCadastramento();
                getline(cin, input);
                

                //Validade da Entrada
                try {
                    opcao = stoi(input);
                    system("cls");
                } catch(const exception& e) {
                    system("cls");
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }
                
                switch (opcao)
                {
                case 1:
                    controle.cadastroAstronauta();
                    getline(cin, input);
                    system("cls");
                    break;
                case 2:
                    controle.cadastroVoos();
                    break;
                case 3:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                    break;
                }
            } while (opcao != 3);
            
            break;
        // Menu Astronauta
        case 2:
            do {
                if (controle.astronautaAll.empty())
                {
                    cout << "Nenhum Astronauta cadastrado ainda!" << endl;
                    break;
                }
                else
                {
                    menuAstronauta();
                    getline(cin, input);

                    // Validade da Entrada
                    try{
                        opcao = stoi(input);
                        system("cls");
                    }
                    catch (const exception &e)
                    {
                        system("cls");
                        cout << "Entrada invalida. Por favor, digite um numero." << endl;
                        continue;
                    }
                
                    switch (opcao)
                    {
                    case 1:
                        do
                        {
                            //Menu Mortos
                            menuMortos();
                            getline(cin, input);

                            // Validade da Entrada
                            try
                            {
                                opcao = stoi(input);
                                system("cls");
                            }
                            catch (const exception &e)
                            {
                                system("cls");
                                cout << "Entrada invalida. Por favor, digite um numero." << endl;
                                continue;
                            }

                            //Menu Lista de Mortos
                            switch (opcao)
                            {
                            case 1:
                                controle.AstronautasMortosCpf();
                                break;
                            case 2:
                                controle.AstronautasMortosNome();
                                break;
                            case 3:
                                controle.AstronautasMortosVoos();
                                break;
                            case 4:
                                break;
                            default:
                                cout << "Opcao invalida" << endl;
                                break;
                            }

                        } while (opcao != 4);

                        break;
                    case 2:
                        controle.AstronautasDisponiveis();
                        break;
                    case 3:
                        controle.AstronautasIndisponiveis();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Opcao invalida" << endl;
                        break;
                    }
                }
            } while (opcao != 4);
            break;
        // Menu Voos
        case 3:
            
            if (controle.voosAll.empty()){
                cout << "Nenhum Voo cadastrado ainda!" << endl;
                break;
            }
            else{
                do {
                    menuVoos();
                    getline(cin, input);

                    // Validade da Entrada
                    try
                    {
                        opcao = stoi(input);
                        system("cls");
                    }
                    catch (const exception &e)
                    {
                        system("cls");
                        cout << "Entrada invalida. Por favor, digite um numero." << endl;
                        continue;
                    }

                    switch (opcao)
                    {
                    case 1:
                        controle.AddAstronautaVoo();
                        break;
                    case 2:
                        controle.RemoAstronautaVoo();
                        break;
                    case 3:
                        controle.PlanejamentoConcluido();
                        break;
                    case 4:
                        do
                        {
                            menuListaVoos();
                            getline(cin, input);

                            //Validade da entrada
                            try{
                                opcao = stoi(input);
                            }
                            catch (const std::exception &e)
                            {
                                cout << "Entrada invalida. Por favor, digite um numero." << endl;
                            }

                            switch (opcao)
                            {
                            case 1:
                                controle.ListaPlanejado();
                                break;
                            case 2:
                                controle.ListaEmCurso();
                                break;
                            case 3:
                                do
                                {
                                    menuListaFinalizados();
                                    getline(cin, input);

                                    try
                                    {
                                        opcao = stoi(input);
                                        system("cls");
                                    }
                                    catch (const std::exception &e)
                                    {
                                        system("cls");
                                        cout << "Entrada invalida. Por favor, digite um numero." << endl;
                                        continue;
                                    }

                                    switch (opcao)
                                    {
                                    case 1:
                                        controle.ListaFimSucesso();
                                        break;
                                    case 2:
                                        controle.ListaFimSemSucesso();
                                        break;
                                    case 3:
                                        break;
                                    default:
                                        cout << "Opcao invalida" << endl;
                                        break;
                                    }
                                } while (opcao != 3);
                                break;

                            default:
                                break;
                            }

                        } while (opcao != 4);

                        cout << "Lista de Voos" << endl;
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Opcao invalida" << endl;
                        break;
                    }
                } while (opcao != 4);
            }
            break;
        
        //Menu Controle de Trafego
        case 4:
            do {
                menuControleTrafego();
                getline(cin, input);

                //Validade da Entrada
                try {
                    opcao = stoi(input);
                    system("cls");
                } catch(const exception& e) {
                    system("cls");
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }

                switch (opcao){
                case 1:
                    controle.LancarVoo();
                    break;
                case 2:
                    controle.ExplodirVoo();
                    break;
                case 3:
                    controle.FinalizarVoo();
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                    break;
                }
            } while (opcao != 4);
            break;
        case 5:
            //Finalizar a Sessao
            cout << "Obrigado por usar os nossos servicos!" << endl;
            break;
        default:
            //Opcao Invalida
            cout << "Opcao invalida"<< endl;
            break;
        }
    } while (opcao != 5);

    /* Imprimir todos os Astronautas
    cout << "Lista de Astronautas: " << endl;
    controle.imprimirAstronautas(); */

    /*Imprimir todos os voos
    cout << "Lista de Voos: " << endl;
    controle.imprimirVoos(); */


    return 0;
}
