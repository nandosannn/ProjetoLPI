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
        cout << "Voos presente: " << endl;
        cout << "Voo - " << elemento << endl;
        cout << "Codigo: " << elementos;
        elemento++;
    }
}

bool Astronauta::verificarListaVoos(){
    return voosParticipados.empty();
}


