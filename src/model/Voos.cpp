#include "../../include/model/Voos.hpp"

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

bool Voos::AdicionarAstronauta(Astronauta& astronauta, list<Astronauta>& AstronautasPresentes){
    for (Astronauta astronautas : AstronautasPresentes)
    {
        if (astronautas.getCpf() ==  astronauta.getCpf())
        {
            return false;
        }
    }
    AstronautasPresentes.push_back(astronauta);
    return true;
}

bool Voos::RemoverAstronauta(string cpf, list<Astronauta>& AstronautasPresentes){
    Astronauta astronautaAux;
    for (auto it = AstronautasPresentes.begin(); it != AstronautasPresentes.end(); ++it)
    {
        astronautaAux = *it;
        if (cpf == astronautaAux.getCpf())
        {
            AstronautasPresentes.erase(it);
            return true;
        }
    }
    return false;
    
}

 //Metodo Controle Geral Voos.cpp
void Voos::statusAstronautaMorto(list<Astronauta>& AstronautasPresentes, list<Astronauta>& astronautaAll){
    for (auto& astronautas : AstronautasPresentes) {
        for (auto& astronautasGeral : astronautaAll)
        {
            if (astronautas.getCpf() == astronautasGeral.getCpf())
            {
                astronautasGeral.statusAstronauta=morto;
            }
            
        }
        
    }
}

void Voos::limparLista(list<Astronauta>& AstronautasPresentes){
        AstronautasPresentes.clear();
    }

//Função classe Voos.cpp
void Voos::statusAstronautoVooFim(list<Astronauta>& AstronautasPresentes, list<Astronauta>& astronautaAll) {
    for (auto& astronautas : AstronautasPresentes) {
        for (auto& astronautasGeral : astronautaAll)
        {
            if (astronautas.getCpf() == astronautasGeral.getCpf())
            {
                astronautasGeral.statusAstronauta=disponivel;
            }
            
        }
        
    }
}
