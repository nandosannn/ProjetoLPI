#include "ControleTrafego.hpp"

//Metodo Cadastro
void ControleTrafego::cadastroAstronauta(){
    string cpf;
    string nome;
    int idade;
    cout << "Cadastramento de Astronauta: " << endl;
    cout << "Digite o cpf do Astronauta: ";
    getline(cin, cpf);
    if (testeAstronauta(cpf))
    {
        system("cls");
        cout << "Astronauta ja cadastrado" << endl;
    }
    else{
        cout << "Digite o nome do Astronauta: ";
        getline(cin, nome);
        cout << "Digite a idade do Astronauta: ";
        cin >> idade;
        Astronauta astronauta(cpf, nome, idade);
        astronauta.statusAstronauta = disponivel;
        astronautaAll.push_back(astronauta);
        getline(cin, cpf);
        system("cls");
        cout << "Cadastro realizado com sucesso!" << endl;
    }
    
    
}

void ControleTrafego::imprimirAstronautas(){
    int elemento = 1;
    for (Astronauta lista : astronautaAll){
        cout << "Astronauta - " << elemento << endl;
        cout << "Nome: " << lista.getNome() << endl;
        cout << "Cpf: " << lista.getCpf() << endl;
        cout << "Idade: " << lista.getIdade() << endl;
        cout << "Status: " << lista.statusAstronauta << endl;
        elemento++;
    } 
}

bool ControleTrafego::testeAstronauta(string input){
    for (Astronauta astronauta : astronautaAll)
    {
        if (input == astronauta.getCpf())
        {
            return true;
        }
        
    }
    return false;
    
}

void ControleTrafego::cadastroVoos(){
    string input;
    int codigo;
    cout << "Digite o codigo do Voo: ";
    getline(cin, input);
    try
    {
        codigo = stoi(input);
        if (testeVoos(codigo))
        {
            system("cls");
            cout << "Voo ja cadastrado" << endl;
        }
        else {
            Voos voo(codigo);
            voo.statusVoo = EmPlanejamento;
            voosAll.push_back(voo);
            system("cls");
            cout << "Cadastro realizado com sucesso!" << endl;
        }
    }
    catch (const exception &e)
    {
        system("cls");
        cout << "Entrada invalida. Por favor, digite apenas numeros." << endl;
    }
}

void ControleTrafego::imprimirVoos(){
    int elemento = 1;
    for (Voos lista : voosAll){
        cout << "Voo - " << elemento << endl;
        cout << "Codigo: " << lista.getCodigo() << endl;
        cout << "Status voo: " << lista.statusVoo << endl;
        elemento++;
    }
}

bool ControleTrafego::testeVoos(int input){
    for (Voos voos : voosAll)
    {
        if (input == voos.getCodigo())
        {
            return true;
        }
        
    }
    return false;
}