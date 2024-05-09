#include "Voos.hpp"

//Construtores
Voos::Voos(){
}

Voos::Voos(int codigo){
    this->codigo = codigo;
}

//Destrutores
Voos::~Voos(){
    AstronautasPresentes.clear();
 }

int Voos::getCodigo(){
    return codigo;
}

//Metodos
void Voos::imprimirAstronautasPresentes(){
    cout << "Astronautas presentes no Voo" << endl;
    for (Astronauta elementos : AstronautasPresentes){
       cout << "Nome: " << elementos.getNome() << endl;
    }
}

void Voos::AdicionarAstronauta(Astronauta astronauta){
    AstronautasPresentes.push_back(astronauta);
}

void Voos::RemoverAstronauta(Astronauta astronauta){
    Astronauta AstronautaAux;
    for (auto it = AstronautasPresentes.begin(); it != AstronautasPresentes.end(); it++)
    {
        AstronautaAux = *it;
        if (AstronautaAux.getNome() == astronauta.getNome())
        {
            it = AstronautasPresentes.erase(it);
        }
        
    }
    
}

