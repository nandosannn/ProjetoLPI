#include "Astronauta.hpp"


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
void Astronauta::setIdade(int idade){
    this->idade=idade;
}


