#include "ControleTrafego.hpp"

//Metodo Adicionar Astronauta
void ControleTrafego::AddAstronautaVoo(list<Astronauta>& astronautaAll, list<Voos>& voosAll){
    Voos vooAux;
    int inputVoo;
    cout << "Digite o codigo do Voo em planejamento que deseja adicionar Astronautas: " << endl;
    cin >> inputVoo;
    cin.ignore();
    string inputAstronauta;
    cout << "Digite o Cpf do Astronauta disponivel: " << endl;
    getline(cin, inputAstronauta);
    bool vooEncontrado = false;
    bool astronautaEncontrado = false;

    for (auto& voos : voosAll){
        if ((inputVoo == voos.getCodigo()) && (voos.statusVoo == EmPlanejamento)){
            vooEncontrado = true;
            for (auto& astronauta : astronautaAll)
            {
                if ((inputAstronauta == astronauta.getCpf()) && (astronauta.statusAstronauta == disponivel))
                {
                    astronautaEncontrado = true;
                    voos.AdicionarAstronauta(astronauta, voos.AstronautasPresentes);
                    astronauta.statusAstronauta = indisponivel;
                    astronauta.voosParticipados.push_back(voos.getCodigo());
                    vooAux = voos;
                    system("cls");
                    cout << "Astronauta " << astronauta.getNome() << " adicionado com sucesso ao voo: " << voos.getCodigo() << endl;
                    break;
                }
                
            }
        }
    }

    if (vooEncontrado == false)
    {
        system("cls");
        cout << "Voo em planejamento nao encontrado!" << endl;
    }
    else {
        if (astronautaEncontrado == false){
            system("cls");
            cout << "Astronauta disponivel nao encontrado!" << endl;
        }
    }
    
    
}

void ControleTrafego::RemoAstronautaVoo(list<Astronauta>& astronautaAll, list<Voos>& voosAll){
    system("cls");
    int inputVoo;
    cout << "Digite o codigo do Voo em planejamento que deseja remover Astronautas: ";
    cin >> inputVoo;
    string inputAstronauta;
    cout << "Digite o Cpf do Astronauta: ";
    cin.ignore();
    getline(cin, inputAstronauta);
    bool vooEncontrado = false;
    bool astronautaEncontrado = false;
    cout << "Chegou aqui" << endl;
    

    
    for (auto& voos : voosAll){
        if ((inputVoo == voos.getCodigo()) && (voos.statusVoo == EmPlanejamento)){
            vooEncontrado = true;
            for (auto& astronautas : astronautaAll)
            {
                if (astronautas.getCpf() == inputAstronauta)
                {
                    astronautaEncontrado = true;
                    astronautas.removerVoosParticipados(voos.getCodigo(), astronautas.voosParticipados);
                    astronautas.statusAstronauta = disponivel;
                    cout << "Astronauta: " << astronautas.getNome() << " removido com sucesso do voo: " << voos.getCodigo() << endl;
                }
                
            }
            
        }
    }

    cout << "Lista de voos: " << endl;
    for (Voos voos : voosAll)
    {
        cout << "Voos: " << voos.getCodigo() << endl;
    }


    cout << "Lista de astronautas no voo: " << endl;
    for (Astronauta astronautas : astronautaAll)
    {
        cout << "Cpf do Astronauta: " << astronautas.getCpf() << endl;
        for (int voosCadastrados : astronautas.voosParticipados)
        {
            cout << "Voos que " << astronautas.getNome() << " participou: " << voosCadastrados << endl;
        }
        
    }
    
    
    if (vooEncontrado == false){
        cout << "Voo em planejamento nao encontrado!" << endl;
    }
    else{
        if (astronautaEncontrado == false){
            cout << "Astronauta dentro do voo nao encontrado!" << endl;
        }
    }
}

void ControleTrafego::PlanejamentoConcluido(list<Voos>& voosAll){
    system("cls");
    int input;
    cout << "Insira o codigo do voo que está pronto para decolar: ";
    cin >> input;
    cin.ignore();
    bool vooEncontrado = false;

    for (auto& voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == EmPlanejamento)){
            vooEncontrado = true;
            voos.statusVoo = Planejado;
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " pronto para decolar!" << endl;
        }
        
    }

    if (vooEncontrado == false){
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    }
}

void ControleTrafego::ListaPlanejado(){
    system("cls");
    cout << "Lista de Voos Planejados:" << endl;
    int elemento = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == Planejado){
            cout << "Voo " << elemento << ": " << voos.getCodigo();
            elemento ++;
        }
    }
    if (elemento == 1){
        system("cls");
        cout << "Nenhum Voo Planejado!" << endl;
    } 
}


void ControleTrafego::ListaEmCurso(){
    cout << "Lista de Voos em Curso:" << endl;
    int elemento = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == EmCurso){
            cout << "Voo " << elemento << ": " << voos.getCodigo();
            elemento ++;
        }
    }
    if (elemento == 1){
        system("cls");
        cout << "Nenhum Voo em Curso!" << endl;
    } 
}


void ControleTrafego::ListaFimSucesso(){
    system("cls");
    cout << "Lista de Voos Finalizados Com Sucesso:" << endl;
    int elementoSucesso = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == FimSucesso){
            cout << "Voo " << elementoSucesso << ": " << voos.getCodigo();
            elementoSucesso ++;
        }
    }
    if (elementoSucesso == 1){
        system("cls");
        cout << "Nenhum Voo Finalizado com Sucesso!" << endl;
    }
}

void ControleTrafego::ListaFimSemSucesso(){
    system("cls");
    cout << "Lista de Voos Finalizados Sem Sucesso:" << endl;
    int elementoSemSuc = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == FimSemSucesso){
            cout << "Voo " << elementoSemSuc << ": " << voos.getCodigo();
            elementoSemSuc ++;
        }
    }
    if (elementoSemSuc == 1){
        system("cls");
        cout << "Nenhum Voo Finalizado Sem Sucesso!" << endl;
    }
}