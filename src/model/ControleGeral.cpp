#include "../../include/model/ControleTrafego.hpp"

void ControleTrafego::LancarVoo(){
    system("clear");
    system("cls");
    int input;
    cout << "Digite o codigo do voo que deseja lancar: ";
    cin >> input;
    cin.ignore();
    cout << input << endl;
    bool teste = false;

    for (Voos& voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == Planejado))
        {
            voos.statusVoo = EmCurso;
            teste = true;
            system("clear");
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " em curso!" << endl;
        }
        
    }

    if (teste == false){
        system("clear");
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    } 
}

void ControleTrafego::ExplodirVoo(list<Voos>& voosAll, list<Astronauta>& astronautaAll){
    system("clear");
    system("cls");
    int input;
    cout << "Digite o codigo do voo que precisa explodir: ";
    cin >> input;
    cin.ignore();
    bool teste = false;

    for (Voos& voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == EmCurso))
        {
            voos.statusVoo = FimSemSucesso;
            teste = true;
            //Chama das funções na Classe ControleTrafego
            voos.statusAstronautaMorto(voos.AstronautasPresentes, astronautaAll);
            voos.limparLista(voos.AstronautasPresentes);
            system("clear");
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " explodiu e os astronautas estao mortos!" << endl;
        }
        
    }

    if (teste == false){
        system("clear");
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    } 
}

void ControleTrafego::FinalizarVoo(list<Voos>& voosAll, list<Astronauta>& astronautaAll){
    system("clear");
    system("cls");
    int input;
    cout << "Digite o codigo do voo que deseja finalizar: ";
    cin >> input;
    cin.ignore();
    bool teste = false;

    for (auto& voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == EmCurso))
        {
            voos.statusVoo = FimSucesso;
            teste = true;
            voos.statusAstronautoVooFim(voos.AstronautasPresentes, astronautaAll);
            voos.limparLista(voos.AstronautasPresentes);
            
            /*
            cout << "Astronautas presentes no voo: " << endl;
            for (auto voosPresentes : voos.AstronautasPresentes)
            {
                cout << "Astronauta: " << voosPresentes.getNome() << endl;
                cout << "Status: " << voosPresentes.statusAstronauta << endl;
            }
            cout << endl;
            cout << "Astronautas presentes na lista astronautasAll: " << endl;
            for (auto astronautas : astronautaAll)
            {
                cout << "Astronauta: " << astronautas.getNome()<< endl;
                cout << "Status: " << astronautas.statusAstronauta<< endl;
            }
            */
            system("clear");
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " finalizado com sucesso!" << endl;
        }
        
    }

    if (teste == false){
        system("clear");
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    } 
}