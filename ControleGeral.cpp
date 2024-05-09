#include "ControleTrafego.hpp"

void ControleTrafego::LancarVoo(){
    int input;
    cout << "Digite o codigo do voo que deseja lancar: ";
    cin >> input;
    bool teste = false;

    for (Voos voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == Planejado))
        {
            voos.statusVoo = EmCurso;
            teste = true;
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " em curso!" << endl;
            

        }
        
    }

    if (teste == false){
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    } 
}

void ControleTrafego::ExplodirVoo(){
    int input;
    cout << "Digite o codigo do voo que precisa explodir: ";
    cin >> input;
    bool teste = false;

    for (Voos voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == EmCurso))
        {
            voos.statusVoo = FimSemSucesso;
            teste = true;
            for (Astronauta astronauta : voos.AstronautasPresentes){
                astronauta.statusAstronauta = morto;
            }
            voos.AstronautasPresentes.clear();
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " nao exite mais e os astronautas estao mortos!" << endl;
        }
        
    }

    if (teste == false){
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    } 
}

void ControleTrafego::FinalizarVoo(){
    int input;
    cout << "Digite o codigo do voo que deseja finalizar: ";
    cin >> input;
    bool teste = false;

    for (Voos voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == EmCurso))
        {
            voos.statusVoo = FimSemSucesso;
            teste = true;
            for (Astronauta astronauta : voos.AstronautasPresentes){
                astronauta.statusAstronauta = disponivel;
            }
            voos.AstronautasPresentes.clear();
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " finalizado com sucesso!" << endl;
        }
        
    }

    if (teste == false){
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    } 
}