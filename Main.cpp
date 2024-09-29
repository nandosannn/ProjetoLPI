#include <iostream>
#include <string>

#include "include/model/Menu.hpp"
#include "include/model/ControleTrafego.hpp"
#include "include/model/Astronauta.hpp"
#include "include/model/Voos.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    system("clear");
    cout << "Bem-vindo ao Centro de Controle Espacial!" << endl;
    cout << endl;
    cout << "Menu Principal" << endl;
    cout << "Escolha uma opcao abaixo para comecar:" << endl;
    
    string inputPrincipal, inputSecundario, inputTerciario, inputQuartenario;
    int opcaoPrincipal, opcaoSecundaria, opcaoTerciaria, opcaoQuartenaria;

    //Declarações para ControleTrafego
    ControleTrafego controle;

    //Menu Cadastramento
    do {
        menuPrincipal();
        getline(cin, inputPrincipal);

        //Validade da Entrada
        try {
            opcaoPrincipal = stoi(inputPrincipal);
            system("clear");
        } catch(const exception& e) {
            system("clear");
            cout << "Entrada invalida. Por favor, digite um numero." << endl;
            continue;
        }

        //Menu Principal
       
        switch (opcaoPrincipal){
        
        
        case 1:
            do {
                menuCadastramento();
                getline(cin, inputSecundario);
                

                //Validade da Entrada
                try {
                    opcaoSecundaria = stoi(inputSecundario);
                    system("clear");
                } catch(const exception& e) {
                    system("clear");
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }
                
                switch (opcaoSecundaria)
                {
                case 1:
                    controle.cadastroAstronauta();
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
            } while (opcaoSecundaria != 3);
            
            break;
        // Menu Astronauta
        case 2:
            do {
                if (controle.astronautaAll.empty())
                {
                    cout << "Nenhum Astronauta cadastrado ainda!" << endl;
                    break;
                }
                else{
                    menuAstronauta();
                    getline(cin, inputSecundario);

                    // Validade da Entrada
                    try{
                        opcaoSecundaria = stoi(inputSecundario);
                        system("clear");
                    }
                    catch (const exception &e)
                    {
                        system("clear");
                        cout << "Entrada invalida. Por favor, digite um numero." << endl;
                        continue;
                    }
                
                    switch (opcaoSecundaria)
                    {
                    case 1:
                        do
                        {
                            //Menu Mortos
                            menuMortos();
                            getline(cin, inputTerciario);

                            // Validade da Entrada
                            try
                            {
                                opcaoTerciaria = stoi(inputTerciario);
                                system("clear");
                            }
                            catch (const exception &e)
                            {
                                system("clear");
                                cout << "Entrada invalida. Por favor, digite um numero." << endl;
                                continue;
                            }

                            //Menu Lista de Mortos
                            switch (opcaoTerciaria)
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

                        } while (opcaoTerciaria != 4);
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
            } while (opcaoSecundaria != 4);
            break;
        // Menu Voos
        case 3:
            do
            {
                if (controle.voosAll.empty())
                {
                    cout << "Nenhum Voo cadastrado ainda!" << endl;
                    break;
                }
                else
                {
                    menuVoos();
                    getline(cin, inputSecundario);

                    // Validade da Entrada
                    try
                    {
                        opcaoSecundaria = stoi(inputSecundario);
                        system("clear");
                    }
                    catch (const exception &e)
                    {
                        system("clear");
                        cout << "Entrada invalida. Por favor, digite um numero." << endl;
                        continue;
                    }
                    
                    switch (opcaoSecundaria)
                    {
                    case 1:
                        cout << endl;
                        controle.AddAstronautaVoo(controle.astronautaAll, controle.voosAll);
                        break;
                    case 2:
                        /*
                        //Impressão teste -----------------------------------------------------------------------------
                        cout << endl;
                        cout << "Astronautas presentes no voo: " << endl;
                        for (Voos voos : controle.voosAll)
                        {
                            for (Astronauta astronauta : voos.AstronautasPresentes)
                            {
                                cout << "Astronauta : " << astronauta.getNome() << endl;
                            }
                            
                        }
                        cout << endl;
                        cout << "Voos que astronauta participou: " << endl;
                        for (Astronauta astronautas : controle.astronautaAll)
                        {
                            for (int voos : astronautas.voosParticipados)
                            {
                                cout << "Astronauta: " << astronautas.getNome() << " participou do voo: " << voos << endl;
                            }
                            
                        }
                        //Impressão teste -----------------------------------------------------------------------------
                        */
                        controle.RemoAstronautaVoo(controle.astronautaAll, controle.voosAll);
                        break;
                    case 3:
                        controle.PlanejamentoConcluido(controle.voosAll);
                        break;
                    //Menu Listas Voos
                    case 4:
                        do
                        {
                            menuListaVoos();
                            getline(cin, inputTerciario);

                            // Validade da entrada
                            try
                            {
                                opcaoTerciaria = stoi(inputTerciario);
                                system("clear");
                            }
                            catch (const std::exception &e)
                            {
                                system("clear");
                                cout << "Entrada invalida. Por favor, digite um numero." << endl;
                            }

                            switch (opcaoTerciaria)
                            {
                            case 1:
                                controle.ListaPlanejado();
                                break;
                            case 2:
                                controle.ListaEmCurso();
                                break;
                            // Lista Finalizados
                            case 3:
                                do
                                {
                                    menuListaFinalizados();
                                    getline(cin, inputQuartenario);

                                    try
                                    {
                                        opcaoQuartenaria = stoi(inputQuartenario);
                                        system("clear");
                                    }
                                    catch (const std::exception &e)
                                    {
                                        system("clear");
                                        cout << "Entrada invalida. Por favor, digite um numero." << endl;
                                        continue;
                                    }

                                    switch (opcaoQuartenaria)
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
                                } while (opcaoQuartenaria != 3);
                                break;
                            case 4:
                                break;
                            default:
                                cout << "Opcao invalida" << endl;
                                break;
                            }

                        } while (opcaoTerciaria != 4);
                        break; 
                    case 5:
                        break;
                    default:
                        break;
                    }
                }
                
            } while (opcaoSecundaria != 5);
            break;
        //Menu Controle de Trafego
        case 4:
            do {
                menuControleTrafego();
                getline(cin, inputSecundario);

                //Validade da Entrada
                try {
                    opcaoSecundaria = stoi(inputSecundario);
                    system("clear");
                } catch(const exception& e) {
                    system("clear");
                    cout << "Entrada invalida. Por favor, digite um numero." << endl;
                    continue;
                }

                switch (opcaoSecundaria)
                {
                case 1:
                    controle.LancarVoo();
                    break;
                case 2:
                    controle.ExplodirVoo(controle.voosAll, controle.astronautaAll);
                    break;
                case 3:
                    controle.FinalizarVoo(controle.voosAll, controle.astronautaAll);
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcao invalida" << endl;
                    break;
                }
            } while (opcaoSecundaria != 4);
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
    } while (opcaoPrincipal != 5);

    /*
    //Imprimir todos os Astronautas
    cout << "Lista de Astronautas: " << endl;
    controle.imprimirAstronautas();
    
    cout << endl;
    //Imprimir todos os voos
    cout << "Lista de Voos: " << endl;
    controle.imprimirVoos();
    */
    return 0;
}
