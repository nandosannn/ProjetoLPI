#include "ControleTrafego.hpp"

//Metodo Adicionar Astronauta
void ControleTrafego::AddAstronautaVoo(list<Astronauta>& astronautaAll, list<Voos>& voosAll){
    system("clear");
    system("cls");
    cout << endl;
    int inputVoo;
    cout << "Digite o codigo do Voo em planejamento que deseja adicionar Astronautas: ";
    cin >> inputVoo;
    cin.ignore();
    string inputAstronauta;
    cout << "Digite o Cpf do Astronauta disponivel: ";
    getline(cin, inputAstronauta);
    bool vooEncontrado = false;
    bool astronautaEncontrado = false;
    bool vooAdicionadoAst = false;

    for (auto& voos : voosAll){
        if ((inputVoo == voos.getCodigo()) && (voos.statusVoo == EmPlanejamento)){
            vooEncontrado = true;
            for (auto& astronauta : astronautaAll)
            {
                if ((inputAstronauta == astronauta.getCpf()) && (astronauta.statusAstronauta == disponivel))
                {
                    astronautaEncontrado = voos.AdicionarAstronauta(astronauta, voos.AstronautasPresentes);
                    vooAdicionadoAst = astronauta.addvoosParticipados(voos.getCodigo(), astronauta.voosParticipados);
                    system("clear");
                    system("cls");
                    if (astronautaEncontrado){
                       cout << "Astronauta " << astronauta.getNome() << " adicionado com sucesso ao voo: " << voos.getCodigo() << endl;
                       astronauta.statusAstronauta = indisponivel;
                    }
                    if (vooAdicionadoAst)
                    {
                        cout << "Voo: " << voos.getCodigo() << " adicionado com sucesso a lista de voos que o Astronauta: " << astronauta.getNome() << " participou!" << endl;
                    }
                    break;
                }
                
            }
        }
    }

    if (vooEncontrado == false)
    {
        system("clear");
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
    system("clear");
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
    bool vooRemovidoAst = false;
    
    for (auto& voos : voosAll){
        if ((inputVoo == voos.getCodigo()) && (voos.statusVoo == EmPlanejamento)){
            vooEncontrado = true;
            for (auto& astronautas : astronautaAll)
            {
                if (astronautas.getCpf() == inputAstronauta)
                {
                    vooRemovidoAst = astronautas.removerVoosParticipados(voos.getCodigo(), astronautas.voosParticipados);
                    astronautaEncontrado = voos.RemoverAstronauta(astronautas.getCpf(), voos.AstronautasPresentes);
                    system("clear");
                    system("cls");
                    if (astronautaEncontrado){
                        cout << "Astronauta: " << astronautas.getNome() << " removido com sucesso do voo: " << voos.getCodigo() << endl;
                        astronautas.statusAstronauta = disponivel;
                    }
                    if (vooRemovidoAst)
                    {
                        cout << "Voo: " << voos.getCodigo() << " removido com sucesso a lista de voos que o Astronauta: " << astronautas.getNome() << " participou!" << endl;
                    }
                }
            } 
        }
    }

    /*
    //Impressão teste -----------------------------------------------------------------------------
    cout << "Lista de Astronautas no voo: " << endl;
    for (Voos voos : voosAll)
    {
        for (Astronauta astronautas : voos.AstronautasPresentes)
        {
            cout << "Astronauta: " << astronautas.getNome() << " no voo: " << voos.getCodigo();
        }
        
    }

    cout << endl;

    cout << "Lista de voos que o astronauta participou: " << endl;
    for (Astronauta astronautas : astronautaAll)
    {
        for (int voosCadastrados : astronautas.voosParticipados)
        {
            cout << "Voos que " << astronautas.getNome() << " participou: " << voosCadastrados << endl;
        }
        
    }
    cout << endl;
    //Impressão teste -----------------------------------------------------------------------------
    */
    
    if (vooEncontrado == false){
        system("clear");
        system("cls");
        cout << "Voo em planejamento nao encontrado!" << endl;
    }
    else{
        if (astronautaEncontrado == false){
            system("clear");
            system("cls");
            cout << "Astronauta dentro do voo nao encontrado!" << endl;
        }
    }
}

void ControleTrafego::PlanejamentoConcluido(list<Voos>& voosAll){
    system("clear");
    system("cls");
    int input;
    cout << "Insira o codigo do voo que esta pronto para decolar: ";
    cin >> input;
    cin.ignore();
    bool vooEncontrado = false;

    for (auto& voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == EmPlanejamento)){
            vooEncontrado = true;
            voos.statusVoo = Planejado;
            system("clear");
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " pronto para decolar!" << endl;
        }
        
    }

    if (vooEncontrado == false){
        system("clear");
        system("cls");
        cout << "Voo nao encontrado!" << endl;
    }
}

void ControleTrafego::ListaPlanejado(){
    system("clear");
    system("cls");
    cout << "Lista de Voos Planejados:" << endl;
    int elemento = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == Planejado){
            cout << "Voo " << elemento << ": " << voos.getCodigo() << endl;
            elemento ++;
        }
    }
    if (elemento == 1){
        system("clear");
        system("cls");
        cout << "Nenhum Voo Planejado!" << endl;
    } 
}


void ControleTrafego::ListaEmCurso(){
    cout << "Lista de Voos em Curso:" << endl;
    int elemento = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == EmCurso){
            cout << "Voo " << elemento << ": " << voos.getCodigo() << endl;
            elemento ++;
        }
    }
    if (elemento == 1){
        system("clear");
        system("cls");
        cout << "Nenhum Voo em Curso!" << endl;
    } 
}


void ControleTrafego::ListaFimSucesso(){
    system("clear");
    system("cls");
    cout << "Lista de Voos Finalizados Com Sucesso:" << endl;
    int elementoSucesso = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == FimSucesso){
            cout << "Voo " << elementoSucesso << ": " << voos.getCodigo() << endl;
            elementoSucesso ++;
        }
    }
    if (elementoSucesso == 1){
        system("clear");
        system("cls");
        cout << "Nenhum Voo Finalizado com Sucesso!" << endl;
    }
}

void ControleTrafego::ListaFimSemSucesso(){
    system("clear");
    system("cls");
    cout << "Lista de Voos Finalizados Sem Sucesso:" << endl;
    int elementoSemSuc = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == FimSemSucesso){
            cout << "Voo " << elementoSemSuc << ": " << voos.getCodigo() << endl;
            elementoSemSuc ++;
        }
    }
    if (elementoSemSuc == 1){
        system("clear");
        system("cls");
        cout << "Nenhum Voo Finalizado Sem Sucesso!" << endl;
    }
}