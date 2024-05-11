#include "ControleTrafego.hpp"

//Metodos Lista Mortos
void ControleTrafego::AstronautasMortosCpf(){
    system("cls");
    int elementos = 1;

    for (Astronauta astronautas : astronautaAll)
    {
        if (astronautas.statusAstronauta == morto)
        {
            cout << "Astronauta morto - " << elementos << " #luto" << endl;
            //cout << "Nome: " << astronautas.getNome() << endl;
            cout << "Cpf: " << astronautas.getCpf() << endl;
            //cout << "Voos que participou: " << endl;
            //astronautas.imprimirVoosPresentes();
            elementos++;
        }  
    }

    if (elementos == 1)
    {
        system("cls");
        cout << "Nenhum astronauta morto #DeusNoControle" << endl;
    }
}

void ControleTrafego::AstronautasMortosNome(){
    system("cls");
    int elementos = 1;

    for (Astronauta astronautas : astronautaAll)
    {
        if (astronautas.statusAstronauta == morto)
        {
            cout << "Astronauta morto - " << elementos << " #luto" << endl;
            cout << "Nome: " << astronautas.getNome() << endl;
            //cout << "Cpf: " << astronautas.getCpf() << endl;
            //cout << "Voos que participou: " << endl;
            //astronautas.imprimirVoosPresentes();
            elementos++;
        }  
    }

    if (elementos == 1)
    {
        system("cls");
        cout << "Nenhum astronauta morto #DeusNoControle" << endl;
    }
}

void ControleTrafego::AstronautasMortosVoos(){
    system("cls");
    int elementos = 1;
    
    for (Astronauta astronautas : astronautaAll)
    {
        if (astronautas.statusAstronauta == morto)
        {
            cout << "Astronauta morto - " << elementos << " #luto" << endl;
            //cout << "Nome: " << astronautas.getNome() << endl;
            //cout << "Cpf: " << astronautas.getCpf() << endl;
            if (astronautas.verificarListaVoos()){
                cout << "Nao participou de nenhum Voo!" << endl;
            }
            else{
                cout << "Voos que participou -  " << elementos << endl;
                astronautas.imprimirVoosPresentes();
                elementos++;
            }
        }  
    }

    if (elementos == 1)
    {
        system("cls");
        cout << "Nenhum astronauta morto #DeusNoControle" << endl;
    }
}


//Metodos Lista Disponiveis
void ControleTrafego::AstronautasDisponiveis(){
    system("cls");
    int elemento=1;
    for (Astronauta elementos : astronautaAll)
    {
        if(elementos.statusAstronauta == disponivel){
             cout << "Astronauta disponivel - " << elemento << endl;
             cout << "Cpf: " << elementos.getCpf() << endl;
             elemento++;
        }
    }

    if (elemento==1)
    {
        system("cls");
        cout << "Nenhum astronauta disponível #QueTristreza" << endl;
    }
    
    
}


//Metodos Lista Disponiveis
void ControleTrafego::AstronautasIndisponiveis(){
    system("cls");
    int elemento=1;
    for (Astronauta elementos : astronautaAll)
    {
        if(elementos.statusAstronauta == indisponivel || elementos.statusAstronauta == morto){
             cout << "Astronauta indisponivel - " << elemento << endl;
             cout << "Cpf: " << elementos.getCpf() << endl;
             elemento++;
        }
    }

    if (elemento==1)
    {
        system("cls");
        cout << "Todos astronautas estao disponiveis #QueAlegria" << endl;
    }
}

