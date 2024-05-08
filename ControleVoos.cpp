#include "ControleTrafego.hpp"

//Metodo Adicionar Astronauta
void ControleTrafego::AddAstronautaVoo(){
    int inputVoo;
    cout << "Digite o codigo do Voo em planejamento que deseja adicionar Astronautas: ";
    cin >> inputVoo;
    string inputAstronauta;
    cout << "Digite o Cpf do Astronauta disponivel: ";
    getline(cin, inputAstronauta);
    bool vooEncontrado = false;
    bool astronautaEncontrado = false;

    for (Voos voos : voosAll){
        if ((inputVoo == voos.getCodigo()) && (voos.statusVoo == EmPlanejamento)){
            for (Astronauta astronauta : astronautaAll)
            {
                if ((inputAstronauta == astronauta.getCpf()) && (astronauta.statusAstronauta == disponivel))
                {
                    voos.AdicionarAstronauta(astronauta);
                    astronauta.statusAstronauta = indisponivel;
                    astronauta.voosParticipados.push_back(voos.getCodigo());
                    system("cls");
                    cout << "Astronauta " << astronauta.getNome() << " adicionado com sucesso ao voo: " << voos.getCodigo() << endl;
                }
                astronautaEncontrado = true;
            }
        vooEncontrado = true;
        }
    }

    if (vooEncontrado == false)
    {
        cout << "Voo em planejamento nao encontrado!" << endl;
    }
    else {
        if (astronautaEncontrado == false){
            cout << "Astronauta disponivel nao encontrado!" << endl;
        }
    }
    
    
}

void ControleTrafego::RemoAstronautaVoo(){
    int inputVoo;
    cout << "Digite o codigo do Voo em planejamento que deseja remover Astronautas: ";
    cin >> inputVoo;
    string inputAstronauta;
    cout << "Digite o Cpf do Astronauta: ";
    getline(cin, inputAstronauta);
    bool vooEncontrado = false;
    bool astronautaEncontrado = false;

    for (Voos voos : voosAll){
        if ((inputVoo == voos.getCodigo()) && (voos.statusVoo == EmPlanejamento)){
            for (Astronauta astronauta : astronautaAll)
            {
                if ((inputAstronauta == astronauta.getCpf()) && (astronauta.statusAstronauta == indisponivel))
                {
                    voos.RemoverAstronauta(astronauta);
                    astronauta.statusAstronauta = disponivel;
                    astronauta.removerVoosParticipados(voos.getCodigo());
                    system("cls");
                    cout << "Astronauta " << astronauta.getNome() << " adicionado com sucesso ao voo: " << voos.getCodigo() << endl;
                }
                astronautaEncontrado = true;
            }
        vooEncontrado = true;
        }
    }

    if (vooEncontrado == false){
        system("cls");
        cout << "Voo em planejamento nao encontrado!" << endl;
    }
    else{
        if (astronautaEncontrado == true){
            system("cls");
            cout << "Astronauta dentro do voo nao encontrado!" << endl;
        }
    }
}

void ControleTrafego::PlanejamentoConcluido(){
    int input;
    cout << "Insira o codigo do voo que está pronto para decolar: ";
    cin >> input;
    bool vooEncontrado = false;

    for (Voos voos : voosAll)
    {
        if ((voos.getCodigo() == input) && (voos.statusVoo == EmPlanejamento)){
            voos.statusVoo = Planejado;
            system("cls");
            cout << "Voo: " << voos.getCodigo() << " pronto para decolar!" << endl;
            vooEncontrado = true;
        }
        
    }

    if (vooEncontrado == false){
         system("cls");
        cout << "Voo nao encontrado!" << endl;
    }
}

void ControleTrafego::ListaPlanejado(){
    cout << "Lista de Voos Planejados:" << endl;
    int elemento = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == Planejado){
            cout << "Voo " << elemento << ": " << voos.getCodigo();
            elemento ++;
        }
    }
    if (elemento == 1){
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
        cout << "Nenhum Voo em Curso!" << endl;
    } 
}


void ControleTrafego::ListaFimSucesso(){
    cout << "Lista de Voos Finalizados Com Sucesso:" << endl;
    int elementoSucesso = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == FimSucesso){
            cout << "Voo " << elementoSucesso << ": " << voos.getCodigo();
            elementoSucesso ++;
        }
    }
    if (elementoSucesso == 1){
        cout << "Nenhum Voo Finalizado com Sucesso!" << endl;
    }
}

void ControleTrafego::ListaFimSemSucesso(){
    cout << "Lista de Voos Finalizados Sem Sucesso:" << endl;
    int elementoSemSuc = 1;
    for (Voos voos : voosAll){
        if (voos.statusVoo == FimSemSucesso){
            cout << "Voo " << elementoSemSuc << ": " << voos.getCodigo();
            elementoSemSuc ++;
        }
    }
    if (elementoSemSuc == 1){
        cout << "Nenhum Voo Finalizado Sem Sucesso!" << endl;
    }
}