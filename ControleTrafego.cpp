#include "ControleTrafego.hpp"

//Construtores
ControleTrafego::ControleTrafego(){

}

//Destrutores
ControleTrafego::~ControleTrafego(){
    
}

//Metodo
void ControleTrafego::cadastroAstronauta(){
    string cpf;
    string nome;
    int idade;
    cout << "Cadastramento de Astronauta: " << endl;
    cout << "Digite o cpf do Astronauta: ";
    getline(cin, cpf);
    cout << "Digite o nome do Astronauta: ";
    getline(cin, nome);
    cout << "Digite a idade do Astronauta: ";
    cin >> idade;
    Astronauta astronauta(cpf, nome, idade);
    astronauta.statusAstronauta = disponivel;
    astronautaAll.push_back(astronauta);
}

void ControleTrafego::imprimirAstronautas(){
    int elemento = 1;
    for (Astronauta lista : astronautaAll){
        cout << "Astronauta - " << elemento << endl;
        cout << "Nome: " << lista.getNome() << endl;
        cout << "Cpf: " << lista.getCpf() << endl;
        cout << "Idade: " << lista.getIdade() << endl;
        elemento++;
    }
    
}