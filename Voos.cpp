#include "Voos.hpp"

//Construtores
Voos::Voos(){
}

Voos::Voos(int codigo){
    this->codigo = codigo;
}

//Destrutores
Voos::~Voos(){

 }

int Voos::getCodigo(){
    return codigo;
}