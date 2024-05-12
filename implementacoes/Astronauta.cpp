#include "cabecalho/Astronauta.hpp"


//Construtores
Astronauta::Astronauta(string cpf, string nome, int idade){
    this->cpf=cpf;
    this->nome=nome;
    this->idade=idade;
}

Astronauta::Astronauta(){

}

//Destrutor
Astronauta::~Astronauta(){
    voosParticipados.clear();
}

 //Encapsuladores
string Astronauta::getCpf(){
    return cpf;
}
string Astronauta::getNome(){
    return nome;
}
int Astronauta::getIdade(){
    return idade;
}
void Astronauta::setCpf(string cpf){
    this->cpf=cpf;
}
void Astronauta::setNome(string nome){
    this->nome=cpf;
}
void Astronauta::setIdade(int idade){
    this->idade=idade;
}

//Metodos

void Astronauta::imprimirVoosPresentes(){
    int elemento = 1;
    for (int elementos : voosParticipados)
    {
        cout << "Voo - " << elemento << ": " << elementos << endl;
        elemento++;
    }
}

bool Astronauta::verificarListaVoos(){
    return voosParticipados.empty();
}

bool Astronauta::removerVoosParticipados(int codigo, list<int>& voosParticipados){
    for (auto it = voosParticipados.begin(); it != voosParticipados.end(); ++it)
    {
        if (codigo == *it)
        {
            it = voosParticipados.erase(it);
            return true;
        }
    }
    return false;
}

bool Astronauta::addvoosParticipados(int codigo, list<int>& voosParticipados){
    for (int voos : voosParticipados)
    {
        if(codigo == voos){
            return false;
        }
    }
    voosParticipados.push_back(codigo);
    return true;
    
}


